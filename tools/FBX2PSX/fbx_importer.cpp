#include "fbx_importer.h"
#include "fbx_parser.h"
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <algorithm>
#include "file_utils.h"
#include "string_utils.h"
#include <functional>
#include <fbxsdk/core/math/fbxaffinematrix.h>

struct Vector3 {
  short x,y,z;
  void Set(float _x, float _y, float _z) {
		x = (short)_x;
		y = (short)_y;
		z = (short)_z;
  }
	bool operator==(const Vector3& pos) {
		return x==pos.x && y == pos.y && z == pos.z;
	}
};

struct Vector2 {
  short x, y;
	void Set(short _x, short _y) {
		x = _x;
		y = _y;
	}
	bool operator==(const Vector2& pos) {
		return x == pos.x && y == pos.y;
	}
};

struct TMesh {

	enum TVertexType {
		VERTEX_POSITION,
		VERTEX_POSITION_UV,
		VERTEX_POSITION_NORMAL,
		VERTEX_POSITION_NORMAL_UV,
		VERTEX_POSITION_NORMAL_COLOR,
		VERTEX_POSITION_COLOR,
		VERTEX_POSITION_COLOR_UV
	};

	struct TTransform {
		float time;
		FbxAMatrix mtx;
	};

	struct TVertex {
		Vector3 pos;
    bool operator==(const TVertex& vertex) {
      return pos == vertex.pos;
    }
	};

	struct TVertexPosColor : public TVertex {
		Vector3 color;
		void init() {
			color.x = 255;
			color.y = 255;
			color.z = 255;
    }
	};

	struct TVertexPosUV : public TVertex {
		Vector2 uv;
		void init() {
			memset(this, 0x0, sizeof(TVertexPosUV));
		}
	};

	struct TVertexPosColorUV : public TVertexPosColor {
		Vector2 uv;
		void init() {
			memset(this, 0x0, sizeof(TVertexPosColorUV));
			TVertexPosColor::init();
		}
	};

	struct TVertexPosNormal : public TVertex {
		Vector3 normal;
		void init() {
			memset(this, 0x0, sizeof(TVertexPosNormal));
		}
	};

	struct TVertexPosNormalColor : public TVertexPosColor {
		Vector3 normal;
		void init() {
			memset(this, 0x0, sizeof(TVertexPosNormal));
			TVertexPosColor::init();
		}
	};

	struct TVertexPosNormalUV : public TVertex {
		Vector3 normal;
		Vector2 uv;
		void init() {
			memset(this, 0x0, sizeof(TVertexPosNormalUV));
		}
	};

	std::string          name;
	void*                vertices;
	int									 nvertices;
	std::vector<int>     indices;
	TVertexType          vertex_type;
	size_t               nbytes_per_vertex;
	FbxAMatrix           fbxMtx;
	unsigned int         nframes;
	TTransform*          transforms;
	std::vector<SVertexInfo> all_vertices; //used to search unique vertexs

  TMesh() : vertex_type(TMesh::VERTEX_POSITION) {}
  int GetVertexIdx(const Vector3 &position) const {
    return -1;
  }

  bool isValid() const {
    return true;
  }

	bool hasColor() const {
		return vertex_type == VERTEX_POSITION_COLOR || vertex_type == VERTEX_POSITION_COLOR_UV || vertex_type == VERTEX_POSITION_NORMAL_COLOR;
	}

	bool hasUVs() const {
		return vertex_type == VERTEX_POSITION_UV || vertex_type == VERTEX_POSITION_NORMAL_UV || vertex_type == VERTEX_POSITION_COLOR_UV;
	}

	bool hasNormals() const {
		return vertex_type == VERTEX_POSITION_NORMAL || vertex_type == VERTEX_POSITION_NORMAL_UV || vertex_type == VERTEX_POSITION_NORMAL_COLOR;
	}
};

typedef std::vector<TMesh> VMeshes;

struct TImporter {

  VMeshes          m_meshes;
  TImportParams    m_params;

	TMesh* addMesh() {
    m_meshes.push_back(TMesh());
		return &m_meshes.back();
	}

  TMesh *getMesh() {
    if(m_meshes.size() > 0)
      return &m_meshes.back();
    return nullptr;
  }

	TMesh* getMeshByName(const std::string& name) {
		for (auto& mesh : m_meshes) {
			if(mesh.name == name)
				return &mesh;
		}
		return nullptr;
	}
};

void setNumVertices(TImporterContext *context, int nvertices) {
  TImporter *importer = static_cast<TImporter *>(context->user_data);
  TMesh &sub_mesh = *importer->getMesh();
  sub_mesh.nvertices = 0;
  if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION) {
    sub_mesh.vertices = new TMesh::TVertex[nvertices];
  }
  else if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION_UV) {
    sub_mesh.vertices = new TMesh::TVertexPosUV[nvertices];
  }
  else if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION_NORMAL) {
    sub_mesh.vertices = new TMesh::TVertexPosNormal[nvertices];
  }
  else if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION_NORMAL_UV) {
    sub_mesh.vertices = new TMesh::TVertexPosNormalUV[nvertices];
  }
	else if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION_NORMAL_COLOR) {
		sub_mesh.vertices = new TMesh::TVertexPosNormalColor[nvertices];
	}
	else if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION_COLOR) {
		sub_mesh.vertices = new TMesh::TVertexPosColor[nvertices];
	}
	else if (sub_mesh.vertex_type == TMesh::VERTEX_POSITION_COLOR_UV) {
		sub_mesh.vertices = new TMesh::TVertexPosColorUV[nvertices];
	}
}

void addMesh(TImporterContext *context, const char *name, FbxAMatrix &mtx) {
  TImporter *importer = static_cast<TImporter *>(context->user_data);
	TMesh* mesh = importer->addMesh();
  assert(mesh);
  mesh->name = name;
	mesh->fbxMtx = mtx;
}

void setFormatVertex(TImporterContext *context, bool has_uvs, bool has_color, bool has_normals, bool has_tangents, bool has_binormals) {
  TImporter *importer = static_cast<TImporter *>(context->user_data);
  TMesh *mesh = importer->getMesh();
	assert(mesh);
	TMesh::TVertexType vertex_type = TMesh::VERTEX_POSITION;
  size_t nbytes_per_vertex = sizeof(TMesh::TVertex);
	switch (importer->m_params.m_vertexFormatOutput) {
		case TImportParams::EVertexFormatOutput::VERTEX_COLOR:
		{
			vertex_type = TMesh::VERTEX_POSITION_COLOR;
			nbytes_per_vertex = sizeof(TMesh::TVertexPosColor);
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_UV:
		{
			vertex_type = TMesh::VERTEX_POSITION_UV;
			nbytes_per_vertex = sizeof(TMesh::TVertexPosUV);
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_COLOR_UV:
		{
			vertex_type = TMesh::VERTEX_POSITION_COLOR_UV;
			nbytes_per_vertex = sizeof(TMesh::TVertexPosColorUV);
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_NORMAL:
		{
			vertex_type = TMesh::VERTEX_POSITION_NORMAL;
			nbytes_per_vertex = sizeof(TMesh::TVertexPosNormal);
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_NORMAL_COLOR:
		{
			vertex_type = TMesh::VERTEX_POSITION_NORMAL_COLOR;
			nbytes_per_vertex = sizeof(TMesh::TVertexPosNormalColor);
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_NORMAL_UV:
		{
			vertex_type = TMesh::VERTEX_POSITION_NORMAL_UV;
			nbytes_per_vertex = sizeof(TMesh::TVertexPosNormalUV);
			break;
		}
	}
  mesh->vertex_type = vertex_type;
  mesh->nbytes_per_vertex = nbytes_per_vertex;
}

int getVertexIndex(TImporterContext* context, const SVertexInfo &vertex) {
	TImporter* importer = static_cast<TImporter*>(context->user_data);
	TMesh* mesh = importer->getMesh();
	std::function<bool(const SVertexInfo&, const SVertexInfo&)> compareFunc;

	if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX || importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_COLOR) {
		compareFunc = SVertexInfo::compareVertex;
	}
	else if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_COLOR_UV || importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_UV) {
		compareFunc = SVertexInfo::compareVertexUVs;
	}
	else if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_NORMAL || importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_NORMAL_COLOR) {
		compareFunc = SVertexInfo::compareVertexNormals;
	}
	else if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_NORMAL_UV) {
		compareFunc = SVertexInfo::compareVertexUVsNormals;
	}
	for (int idx = 0; idx < mesh->all_vertices.size(); ++idx)
	{
		if (compareFunc(vertex, mesh->all_vertices[idx])) 
			return idx;
	}
	//Add New Vertex
	mesh->all_vertices.push_back(vertex);
	return (int)mesh->all_vertices.size()-1;
}
     
void setPosition(TImporterContext *context, int idx, float x, float y, float z) {
  TImporter *importer = static_cast<TImporter *>(context->user_data);
	TMesh* mesh = importer->getMesh();
	assert(mesh);
  char *base = (char *)mesh->vertices;
  char *curr = base + mesh->nbytes_per_vertex * idx;

	FbxAMatrix locMtx;
	FbxVector4 fbxPosition(x, y, z, 1.0f);
	locMtx.SetT(fbxPosition);
	locMtx = mesh->fbxMtx * locMtx;
	locMtx = importer->m_params.m_matrix * locMtx;
	fbxPosition = locMtx.GetT();
  TMesh::TVertex *vtx = (TMesh::TVertex *)curr;
  vtx->pos.Set((float)fbxPosition.mData[0], (float)fbxPosition.mData[1], (float)fbxPosition.mData[2]);
  mesh->indices.push_back(idx);
  mesh->nvertices = std::max(mesh->nvertices, idx+1);
}
void setNormal(TImporterContext *context, int idx, float x, float y, float z) {
  TImporter *importer = static_cast<TImporter *>(context->user_data);
	TMesh* mesh = importer->getMesh();
	assert(mesh);
	if (!mesh->hasNormals())
		return;

	char* base = (char*)mesh->vertices;
	char* curr = base + mesh->nbytes_per_vertex * idx;
	FbxAMatrix locMtx, rotMtx;
	FbxVector4 fbxPosition(x, y, z, 1.0f);
	locMtx.SetT(fbxPosition);
	rotMtx.SetROnly(mesh->fbxMtx.GetR());
	locMtx = rotMtx * locMtx;
	fbxPosition = locMtx.GetT();

	x = (float)fbxPosition.mData[0] * 4096.0f;
	y = (float)fbxPosition.mData[1] * 4096.0f;
	z = (float)fbxPosition.mData[2] * 4096.0f;
	if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_NORMAL) 
	{
		TMesh::TVertexPosNormal* vtx = (TMesh::TVertexPosNormal*)curr;
		vtx->normal.Set(x, y, z);
	}
	else if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_NORMAL_COLOR)
	{
		TMesh::TVertexPosNormalColor* vtx = (TMesh::TVertexPosNormalColor*)curr;
		vtx->normal.Set(x, y, z);
	}
	else if (importer->m_params.m_vertexFormatOutput == TImportParams::EVertexFormatOutput::VERTEX_NORMAL_UV)
	{
		TMesh::TVertexPosNormalUV* vtx = (TMesh::TVertexPosNormalUV*)curr;
		vtx->normal.Set(x, y, z);
	}
}
void setUV(TImporterContext *context, int idx, float u, float v) {
  TImporter *importer = static_cast<TImporter *>(context->user_data);
	TMesh* mesh = importer->getMesh();
	assert(mesh);
	if(!mesh->hasUVs())
		return;

	int u_scale = importer->m_params.m_textureSize[0];
	int v_scale = importer->m_params.m_textureSize[1];
	char* base = (char*)mesh->vertices;
	char* curr = base + mesh->nbytes_per_vertex * idx;
	short u_normalized = (short)(u * (u_scale - 1));
	if (u > 1.0f) {
		u_normalized = (short)(u * u_scale) % (u_scale);
	}
	short v_normalized = (short)(v * (v_scale - 1));
	if (v > 1.0f) {
		v_normalized = (short)(v * v_scale) % (v_scale);
	}
	assert(u_normalized < u_scale);
	assert(v_normalized < v_scale);
	if (importer->m_params.m_flipUVFlags & (int)TImportParams::EFlipUVFlag::VERTICAL_FLIP) {
		v_normalized = (v_scale - 1) - v_normalized;
	}
	if (importer->m_params.m_flipUVFlags & (int)TImportParams::EFlipUVFlag::HORIZONTAL_FLIP) {
		u_normalized = (u_scale - 1) - u_normalized;
	}


	if (mesh->vertex_type == TMesh::VERTEX_POSITION_UV) {
    TMesh::TVertexPosUV *vtx = (TMesh::TVertexPosUV *)curr;
		vtx->uv.Set(u_normalized, v_normalized);
  }
	else if (mesh->vertex_type == TMesh::VERTEX_POSITION_NORMAL_UV) {
		TMesh::TVertexPosNormalUV* vtx = (TMesh::TVertexPosNormalUV*)curr;
		vtx->uv.Set(u_normalized, v_normalized);
	}
	else {
    TMesh::TVertexPosColorUV *vtx = (TMesh::TVertexPosColorUV*)curr;
		vtx->uv.Set(u_normalized, v_normalized);
  }
}

void setColor(TImporterContext* context, int idx, float r, float g, float b, float a) {
	TImporter* importer = static_cast<TImporter*>(context->user_data);
	TMesh* mesh = importer->getMesh();
	assert(mesh);
	if(!mesh->hasColor())
		return;

	char* base = (char*)mesh->vertices;
	char* curr = base + mesh->nbytes_per_vertex * idx;
	if (mesh->vertex_type == TMesh::VERTEX_POSITION_COLOR) {
		TMesh::TVertexPosColor* vtx = (TMesh::TVertexPosColor*)curr;
		vtx->color.Set(r, g, b);
	}
	else if (mesh->vertex_type == TMesh::VERTEX_POSITION_COLOR_UV) {
		TMesh::TVertexPosColorUV* vtx = (TMesh::TVertexPosColorUV*)curr;
		vtx->color.Set(r, g, b);
	}
}

void setTangent(TImporterContext *context, int idx, float x, float y, float z, float w) {
  // not do nothing
}

void setTexture(TImporterContext *context, const char *filename, const char *channel_name) {
	// not do nothing
}

bool writeMeshFile(TMesh &mesh, const std::string &filename, const TImportParams& params) {
  if (!mesh.isValid()) {
    printf("Error! Create mesh invalid\n");
    return false;
  }

  //save binary mesh file
  FILE *f = fopen(filename.c_str(), "wb");
  assert(f);

  std::string name = FileUtils::getFilenameName(filename);
  std::string upper_name = name;
  std::transform(name.begin(), name.end(), upper_name.begin(), std::toupper);

	fprintf(f, "#ifndef _%s_MESH_\n#define _%s_MESH_\n\n", upper_name.c_str(), upper_name.c_str());
	fprintf(f, "#include <types.h>\n");
	fprintf(f, "#include \"dcRender.h\"\n");
	fprintf(f, "\n");
	// print vertexs
	if (mesh.vertex_type == TMesh::VERTEX_POSITION) {
		fprintf(f, "static SDC_Vertex %s_Vertices[] = {\n", mesh.name.c_str());
    const TMesh::TVertex* vertices = (const TMesh::TVertex*)mesh.vertices;
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0}", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z);
      if (idx < mesh.nvertices - 1) 
				fprintf(f, ",\n");
      else
				fprintf(f, "\n");
		}
	}
	else if (mesh.vertex_type == TMesh::VERTEX_POSITION_NORMAL) {
		fprintf(f, "static SDC_VertexNormal %s_Vertices[] = {\n", mesh.name.c_str());
		const TMesh::TVertexPosNormal* vertices = (const TMesh::TVertexPosNormal*)mesh.vertices;
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0, %d, %d, %d, 0 }", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z, vertices[idx].normal.x, vertices[idx].normal.y, vertices[idx].normal.z);
			if (idx < mesh.nvertices - 1)
				fprintf(f, ",\n");
			else
				fprintf(f, "\n");
		}
	}
	else if (mesh.vertex_type == TMesh::VERTEX_POSITION_NORMAL_UV) { 
		fprintf(f, "static SDC_VertexTexturedNormal %s_Vertices[] = {\n", mesh.name.c_str());
		const TMesh::TVertexPosNormalUV* vertices = (const TMesh::TVertexPosNormalUV*)mesh.vertices;
		srand(0);
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0, %d, %d, %d, 0, %d, %d }", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z, vertices[idx].normal.x, vertices[idx].normal.y, vertices[idx].normal.z, vertices[idx].uv.x, vertices[idx].uv.y);
			if (idx < mesh.nvertices - 1)
				fprintf(f, ",\n");
			else
				fprintf(f, "\n");
		}
	}
	else if (mesh.vertex_type == TMesh::VERTEX_POSITION_NORMAL_COLOR) {
		fprintf(f, "static SDC_VertexColorNormal %s_Vertices[] = {\n", mesh.name.c_str());
		const TMesh::TVertexPosNormalColor* vertices = (const TMesh::TVertexPosNormalColor*)mesh.vertices;
		srand(0);
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0, %d, %d, %d, 0, %d, %d, %d, 0 }", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z, vertices[idx].normal.x, vertices[idx].normal.y, vertices[idx].normal.z, rand() % 255, rand() % 255, rand() % 255);
			if (idx < mesh.nvertices - 1)
				fprintf(f, ",\n");
			else
				fprintf(f, "\n");
		}
	}
	else if (mesh.vertex_type == TMesh::VERTEX_POSITION_UV) {
		fprintf(f, "static SDC_VertexTextured %s_Vertices[] = {\n", mesh.name.c_str());
		const TMesh::TVertexPosUV* vertices = (const TMesh::TVertexPosUV*)mesh.vertices;
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0, %d, %d }", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z, vertices[idx].uv.x, vertices[idx].uv.y);
			if (idx < mesh.nvertices - 1)
				fprintf(f, ",\n");
			else
				fprintf(f, "\n");
		}
	}
	else if (mesh.vertex_type == TMesh::VERTEX_POSITION_COLOR) {
		fprintf(f, "static SDC_VertexColor %s_Vertices[] = {\n", mesh.name.c_str());
		const TMesh::TVertexPosColor* vertices = (const TMesh::TVertexPosColor*)mesh.vertices;
		srand(0);
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0, %d, %d, %d, 0 }", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z, rand() % 255, rand() % 255, rand() % 255);
			if (idx < mesh.nvertices - 1)
				fprintf(f, ",\n");
			else
				fprintf(f, "\n");
		}
	}
	else if (mesh.vertex_type == TMesh::VERTEX_POSITION_COLOR_UV) {
		fprintf(f, "static SDC_VertexColorTextured %s_Vertices[] = {\n", mesh.name.c_str());
		const TMesh::TVertexPosColorUV* vertices = (const TMesh::TVertexPosColorUV*)mesh.vertices;
		srand(0);
		for (int idx = 0; idx < mesh.nvertices; ++idx) {
			fprintf(f, "    { %d, %d, %d, 0, %d, %d, %d, 0, %d, %d }", vertices[idx].pos.x, vertices[idx].pos.y, vertices[idx].pos.z, rand() % 255, rand() % 255, rand() % 255, vertices[idx].uv.x, vertices[idx].uv.y);
			if (idx < mesh.nvertices - 1)
				fprintf(f, ",\n");
			else
				fprintf(f, "\n");
		}
	}
	fprintf(f, "};\n");

	fprintf(f, "static u_short %s_Indices[] = {\n    ", mesh.name.c_str());
  constexpr int indexs_by_line = 32;
	int nindices = (int)mesh.indices.size();
  //swap indices to psx format
	for (int idx = 0; idx < nindices; idx += 3) {
		int prev_idx = mesh.indices[idx + 1];
		mesh.indices[idx + 1] = mesh.indices[idx + 2];
		mesh.indices[idx + 2] = prev_idx;
	}
	for (int idx = 0; idx < nindices; ++idx) {
	  fprintf(f, "%d", mesh.indices[idx]);
    if (idx < nindices-1)
    {
			fprintf(f, ", ");
    }
    if (idx > 0 && idx % indexs_by_line == 0)
    {
			fprintf(f, "\n    ");
    }
	}
	fprintf(f, "\n};\n");
  std::string vertex_type_str = "POLIGON_VERTEX";
	switch (params.m_vertexFormatOutput) {
		case TImportParams::EVertexFormatOutput::VERTEX_COLOR:
		{
			vertex_type_str = "POLIGON_VERTEX_COLOR";
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_COLOR_UV:
		{
			vertex_type_str = "POLIGON_VERTEX_TEXTURED_COLOR";
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_UV:
		{
			vertex_type_str = "POLIGON_VERTEX_TEXTURED";
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_NORMAL:
		{
			vertex_type_str = "POLIGON_VERTEX_NORMAL";
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_NORMAL_COLOR:
		{
			vertex_type_str = "POLIGON_VERTEX_COLOR_NORMAL";
			break;
		}
		case TImportParams::EVertexFormatOutput::VERTEX_NORMAL_UV:
		{
			vertex_type_str = "POLIGON_VERTEX_TEXTURED_NORMAL";
			break;
		}
	}
  fprintf(f,"static SDC_Mesh3D %s_Mesh = {%s_Vertices, %s_Indices, NULL, %d, %d, %s};\n", mesh.name.c_str(), mesh.name.c_str(), mesh.name.c_str(), nindices, mesh.nvertices, vertex_type_str.c_str());

	fprintf(f, "#endif");

  fclose(f);
  return true;
}

std::string TImportParams::getRelativeFolder(const std::string &folder) const {
  std::string new_folder = folder;
  StringUtils::replaceStr(new_folder, m_rootFolder, "");
  return new_folder;
}

std::string TImportParams::getAbsoluteFolder(const std::string &folder) const {
  if(!folder.empty() && folder[1] != ':')
    return m_rootFolder + folder;
  return folder;
}

void TImportParams::refreshAbsolutePaths() {
	if (m_rootFolder.back() != '\\') {
    m_rootFolder += "\\";
	}
  if (m_outFolderMeshes.empty() || m_outFolderMeshes[1] != ':') {
    m_outFolderMeshes = m_rootFolder + m_outFolderMeshes;
  }
	if (m_outFolderMeshes.back() != '\\') {
		m_outFolderMeshes += "\\";
	}
}

void doMeshes(const char *filename, const TImportParams &params, TImporter &fbx) {
  // Meshes
  for (auto &m : fbx.m_meshes) {
    std::string ofilename = params.m_outFolderMeshes + std::string(m.name) + ".h";
    if (params.m_overwriteMeshes || !FileUtils::existsFile(ofilename))
    {
      writeMeshFile(m, ofilename, params);
    }
  }
}

bool importMeshFromFBX(const char *filename, const TImportParams &params) {
  TImporter fbx;
  fbx.m_params = params;
  TImporterContext context;
  context.inter = new SFBXParserInterface();
  context.inter->addMesh = &addMesh;
  context.inter->setNumVertices = &setNumVertices;
  context.inter->setFormatVertex = &setFormatVertex;
	context.inter->setPosition = &setPosition;
	context.inter->setColor = &setColor;
  context.inter->setNormal = &setNormal;
  context.inter->setUV = &setUV;
  context.inter->setTangent = &setTangent;
  context.inter->setBinormal = nullptr;
  context.inter->setTexture = &setTexture;
	context.inter->getVertexIndex = &getVertexIndex;
  context.user_data =(void *)(&fbx);
  ResultParserFBX res = parserFBX(filename, &context);
	if (params.m_displayNodes) {
		/*
		VECTOR gNodesA[] = { 
    {-957,81,-390},
    {-402,81,-390},
    {-27,81,-390},
    {-27,81,-211},
    {-166,81,-169},
    {-166,81,192},
    {124,81,212},
    {167,81,394},
    {678,81,394},
    {934,81,394}
		};
		*/
		std::set<std::string> nodesA;
		std::set<std::string> nodesB;
		for (auto& curr_mesh : fbx.m_meshes) {
			if (curr_mesh.name.find("_NodeA") != std::string::npos) {
				nodesA.insert(curr_mesh.name);
			}
			else if (curr_mesh.name.find("_NodeB") != std::string::npos) {
				nodesB.insert(curr_mesh.name);
			}
		}
		printf("VECTOR gNodesA[] = {\n");
		int idx = 0;
		for (auto& curr_name : nodesA) {
			auto mesh = fbx.getMeshByName(curr_name);
			assert(mesh);
			FbxVector4 loc = mesh->fbxMtx.GetT();
			printf("{%d, %d, %d}", (int)loc.mData[0], (int)loc.mData[1], (int)loc.mData[2]);
			++idx;
			if (idx < nodesA.size()) {
				printf(",");
			}
			printf(" // %s \n", curr_name.c_str());
		}
		printf("};\n");

		printf("VECTOR gNodesB[] = {\n");
		idx = 0;
		for (auto& curr_name : nodesB) {
			auto mesh = fbx.getMeshByName(curr_name);
			assert(mesh);
			FbxVector4 loc = mesh->fbxMtx.GetT();
			printf("{%d, %d, %d}", (int)loc.mData[0], (int)loc.mData[1], (int)loc.mData[2]);
			++idx;
			if (idx < nodesB.size()) {
				printf(",");
			}
			printf(" // %s \n", curr_name.c_str());
		}
		printf("};\n");

		return true;
	}
  if (res == ResultParserFBX::OK) {
    doMeshes(filename, params, fbx);
  }
	else if (res == ResultParserFBX::FBX_MUST_BE_TRIANGLES) {
		printf("Error: ResultParserFBX = FBX Must Be Triangles");
	}

  return res == ResultParserFBX::OK;
}
