#pragma once

class cXml
{
public:
    
    struct Node
    {
        unsigned short childNumber;
        unsigned short firstChildIndex;
        unsigned short attributeNumber;
        unsigned short dataIndex;
    };

    struct Data
    {
        unsigned short nameOffset;
        unsigned short dataOffset;
    };
    virtual ~cXml() {};
};