#pragma once

#include "../Math/Bounds.hpp"
#include "../Math/RealPlane3D.hpp"
#include "../Math/RealPoint3D.hpp"

#include "../Tags/TagBlock.hpp"
#include "../Tags/TagData.hpp"
#include "../Tags/TagStructureReference.hpp"

namespace Blam::Geometry
{
	enum class RenderGeometryRuntimeFlags : int
	{
		None = 0,
		Processed = 1 << 0,
		Available = 1 << 1,
		HasValidBudgets = 1 << 2,
		ManualResourceCalibration = 1 << 3,
		KeepRawGeometry = 1 << 4,
		DoNotUseCompressedVertexPositions = 1 << 5,
		PcaAnimationTableSorted = 1 << 6,
		HasDualQuat = 1 << 7
	};
	static_assert(sizeof(RenderGeometryRuntimeFlags) == 0x4);

	enum class RenderMeshPartType : char
	{
		NotDrawn,
		OpaqueShadowOnly,
		OpaqueShadowCasting,
		OpaqueNonshadowing,
		Transparent,
		LightmapOnly
	};
	static_assert(sizeof(RenderMeshPartType) == 0x1);

	enum class RenderMeshPartFlags : unsigned char
	{
		None,
		IsWaterSurface = 1 << 0,
		PerVertexLightmapPart = 1 << 1,
		RenderInZPrepass = 1 << 2,
		CanBeRenderedInDrawBundles = 1 << 3,
		DrawCullDistanceMedium = 1 << 4,
		DrawCullDistanceClose = 1 << 5,
		DrawCullRenderingShields = 1 << 6,
		DrawCullRenderingActiveCamo = 1 << 7
	};
	static_assert(sizeof(RenderMeshPartFlags) == 0x1);

	struct RenderMeshPart
	{
		short MaterialIndex;
		short TransparentSortingIndex;
		unsigned short FirstIndex;
		unsigned short IndexCount;
		short FirstSubPartIndex;
		short SubPartCount;
		RenderMeshPartType Type : 8;
		RenderMeshPartFlags Flags : 8;
		unsigned short VertexCount;
	};
	static_assert(sizeof(RenderMeshPart) == 0x10);

	struct RenderMeshSubPart
	{
		unsigned short FirstIndex;
		unsigned short IndexCount;
		short PartIndex;
		unsigned short VertexCount;
	};
	static_assert(sizeof(RenderMeshSubPart) == 0x8);

	enum class RenderMeshFlags : unsigned char
	{
		None = 0,
		MeshHasVertexColor = 1 << 0,
		UseRegionIndexForSorting = 1 << 1,
		CanBeRenderedInDrawBundles = 1 << 2,
		MeshIsCustomShadowCaster = 1 << 3,
		MeshIsUnindexed = 1 << 4,
		MashShouldRenderInZPrepass = 1 << 5,
		MeshHasWater = 1 << 6,
		MeshHasDecal = 1 << 7
	};
	static_assert(sizeof(RenderMeshFlags) == 0x1);

	enum class RenderMeshType : char
	{
		World,
		Rigid,
		Skinned,
		ParticleModel,
		FlatWorld,
		FlatRigid,
		FlatSkinned,
		Screen,
		Debug,
		Transparent,
		Particle,
		Contrail,
		LightVolume,
		SimpleChud,
		FancyChud,
		Decorator,
		TinyPosition,
		PatchyFog,
		Water,
		Ripple,
		Implicit,
		Beam,
		DualQuat
	};
	static_assert(sizeof(RenderMeshType) == 0x1);

	enum class RenderMeshPrtType : char
	{
		None,
		Ambient,
		Linear,
		Quadratic
	};
	static_assert(sizeof(RenderMeshPrtType) == 0x1);

	enum class RenderMeshPrimitiveType : char
	{
		PointList,
		LineList,
		LineStrip,
		TriangleList,
		TriangleFan,
		TriangleStrip
	};
	static_assert(sizeof(RenderMeshPrimitiveType) == 0x1);

	struct RenderMeshInstancedGeometry
	{
		short Section1;
		short Section2;
		Tags::TagBlock<short> Contents;
	};
	static_assert(sizeof(RenderMeshInstancedGeometry) == 0x10);

	struct RenderMesh
	{
		Tags::TagBlock<RenderMeshPart> Parts;
		Tags::TagBlock<RenderMeshSubPart> SubParts;
		short VertexBufferIndices[8];
		short IndexBufferIndices[2];
		RenderMeshFlags Flags : 8;
		char RigidNodeIndex;
		RenderMeshType Type : 8;
		RenderMeshPrtType PrtType : 8;
		RenderMeshPrimitiveType PrimitiveType : 8;
		char : 8;
		short : 16;
		Tags::TagBlock<RenderMeshInstancedGeometry> InstancedGeometry;
		Tags::TagBlock<short> Water;
	};
	static_assert(sizeof(RenderMesh) == 0x4C);

	enum class RenderGeometryCompressionFlags : unsigned short
	{
		None = 0,
		CompressedPosition = 1 << 0,
		CompressedTexcoord = 1 << 1,
		CompressionOptimized = 1 << 2
	};
	static_assert(sizeof(RenderGeometryCompressionFlags) == 0x2);

	struct RenderGeometryCompression
	{
		RenderGeometryCompressionFlags Flags : 16;
		short : 16;
		Math::Bounds<float> X;
		Math::Bounds<float> Y;
		Math::Bounds<float> Z;
		Math::Bounds<float> U;
		Math::Bounds<float> V;
	};
	static_assert(sizeof(RenderGeometryCompression) == 0x2C);

	struct RenderGeometryBoundingSphere
	{
		Math::RealPlane3D Plane;
		Math::RealPoint3D Position;
		float Radius;
		char NodeIndices[4];
		float NodeWeights[3];
	};
	static_assert(sizeof(RenderGeometryBoundingSphere) == 0x30);

	struct RenderGeometryUnknown
	{
		unsigned char Unknown1;
		unsigned char Unknown2;
		short Unknown3;
		Tags::TagData<char> Unknown4;
	};
	static_assert(sizeof(RenderGeometryUnknown) == 0x18);

	struct RenderGeometryUnknownSection
	{
		Tags::TagData<char> Unknown1;
		Tags::TagBlock<short> Unknown2;
	};
	static_assert(sizeof(RenderGeometryUnknownSection) == 0x20);

	struct RenderGeometryPerMeshNodeMap
	{
		Tags::TagBlock<unsigned char> NodeIndices;
	};
	static_assert(sizeof(RenderGeometryPerMeshNodeMap) == 0xC);

	struct RenderGeometryPerMeshSubPartVisibility
	{
		Tags::TagBlock<RenderGeometryBoundingSphere> BoundingSpheres;
	};
	static_assert(sizeof(RenderGeometryPerMeshSubPartVisibility) == 0xC);

	struct RenderGeometryPerMeshLodData
	{
		Tags::TagBlock<long> Indices;
		short VertexBufferIndex;
		short : 16;
	};

	struct RenderGeometry
	{
		RenderGeometryRuntimeFlags RuntimeFlags : 32;
		Tags::TagBlock<RenderMesh> Meshes;
		Tags::TagBlock<RenderGeometryCompression> Compression;
		Tags::TagBlock<RenderGeometryBoundingSphere> BoundingSpheres;
		Tags::TagBlock<RenderGeometryUnknown> Unknown;
		long : 32;
		long : 32;
		long : 32;
		Tags::TagBlock<RenderGeometryUnknownSection> UnknownSections;
		Tags::TagBlock<RenderGeometryPerMeshNodeMap> PerMeshNodeMaps;
		Tags::TagBlock<RenderGeometryPerMeshSubPartVisibility> PerMeshSubPartVisibility;
		long : 32;
		long : 32;
		long : 32;
		Tags::TagBlock<RenderGeometryPerMeshLodData> PerMeshLodData;
		void *Pageable;
		long : 32;
	};
	static_assert(sizeof(RenderGeometry) == 0x84);

	enum class VertexBufferFormat : short
	{
		Invalid,
		World,                // Size = 0x38
		Rigid,                // Size = 0x38
		Skinned,              // Size = 0x40
		StaticPerPixel,       // Size = 0x8
		Unknown5,             // Size = 0x4
		StaticPerVertex,      // Size = 0x14
		Unknown7,             // Size = 0x14
		Unused8,              // Invalid
		AmbientPrt,           // Size = 0x4
		LinearPrt,            // Size = 0x4
		QuadraticPrt,         // Size = 0x24
		UnknownC,             // Size = 0x14
		UnknownD,             // Size = 0x10
		StaticPerVertexColor, // Size = 0xC
		UnknownF,             // Size = 0x18
		Unused10,             // Invalid
		Unused11,             // Invalid
		Unused12,             // Invalid
		Unused13,             // Invalid
		TinyPosition,         // Size = 0x8
		Unknown15,            // Size = 0x4
		Unknown16,            // Size = 0x4
		Unknown17,            // Size = 0x4
		Decorator,            // Size = 0x20
		ParticleModel,        // Size = 0x20
		Unknown1A,            // Size = 0xC
		Unknown1B,            // Size = 0x24
		Unknown1C,            // Size = 0x80
		Unused1D              // Invalid
	};
	static_assert(sizeof(VertexBufferFormat) == 0x2);

	struct VertexBufferDefinition
	{
		long Count;
		VertexBufferFormat Format : 16;
		short VertexSize;
		Tags::TagData<char> Data;
		long : 32;
	};
	static_assert(sizeof(VertexBufferDefinition) == 0x20);

	enum class IndexBufferFormat : long
	{
		PointList,
		LineList,
		LineStrip,
		TriangleList,
		TriangleFan,
		TriangleStrip
	};
	static_assert(sizeof(IndexBufferFormat) == 0x4);

	struct IndexBufferDefinition
	{
		IndexBufferFormat Format : 32;
		Tags::TagData<char> Data;
		long : 32;
		long : 32;
	};
	static_assert(sizeof(IndexBufferDefinition) == 0x20);

	struct RenderGeometryApiResourceDefinition
	{
		long : 32;
		long : 32;
		long : 32;
		long : 32;
		long : 32;
		long : 32;
		Tags::TagBlock<Tags::TagStructureReference<VertexBufferDefinition>> VertexBuffers;
		Tags::TagBlock<Tags::TagStructureReference<IndexBufferDefinition>> IndexBuffers;
	};
	static_assert(sizeof(RenderGeometryApiResourceDefinition) == 0x30);
}