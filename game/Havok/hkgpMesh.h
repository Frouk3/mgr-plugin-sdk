#pragma once

struct hkgpMesh
{
    class IConvexOverlap
    {
    public:

        virtual ~IConvexOverlap() {};
    };
};

class IConvexOverlapImpl : public hkgpMesh::IConvexOverlap{};