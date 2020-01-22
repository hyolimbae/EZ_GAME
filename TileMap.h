#pragma once
#include "GgaetIp.h"
#include "Tile.h"

#define TILENUM_X 11
#define TILENUM_Y 11

#define TILEWIDTH 128
#define TILEHEIGHT 32

class TilePick;

struct testInfo
{
	string name;
	float r;
	float g;
	float b;
	int depth;
};

class TileMap : public Script
{
private:
	vector<Object*> vTotal;
	bool _isStart = false;
	map<ATTRIBUTE, testInfo> attributeInfo;

	Object* tilePick;

public:
	virtual void Init() override;
	virtual void Update() override;

	void SetTile(Vector2 index, ATTRIBUTE attribute);
	void SetLink(Object* tilePick) { this->tilePick = tilePick; }


	vector<Object*> GetVTotal() { return vTotal; }
};

