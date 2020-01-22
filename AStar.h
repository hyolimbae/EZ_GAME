#pragma once
#include "GgaetIp.h"
#include "Tile.h"
#include "TileMap.h"
#include "Character.h"

#define TILENUM_X 11
#define TILENUM_Y 11

#define TILEWIDTH 128
#define TILEHEIGHT 32


class AStar : public Script
{
private:

	vector<Object*> vTotal;
	vector<Object*> vOpen;
	vector<Object*> vClosed;
	vector<Object*> path;

	bool _isStart = false;
	bool allowDiagonalMove = true;

	Vector2 startIndex;
	Vector2 currentIndex;
	Vector2 targetIndex;

	TileMap* tileMap;
	Character* target;

	int count = 0;

public:
	virtual void Init() override;
	virtual void Update() override;


	void AddOpenList();
	void FindPath();


	void SetTarget(Vector2 targetIndex) 
	{
		this->targetIndex = target->GetIndex();
		vClosed.push_back(vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]);
		Tile* temp = vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]->GetComponent<Tile>();
		temp->SetIsOpen(true);
		temp->SetCostFromStart(0);
		temp->SetCostToGoal(0);
		temp->SetTotalCost(0);
		temp->SetParent(NULL);
	}

	void MakeMove();
	void SetStartIndex(Vector2 startIndex) { this->startIndex = startIndex; }

	void SetLinkMap(TileMap* tileMap) { this->tileMap = tileMap; }
	void SetLinkTarget(Character* target) { this->target = target; }

	void SetAllowDiagonalMove(bool allow) { allowDiagonalMove = allow; }
	
};

