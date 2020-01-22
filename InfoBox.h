#pragma once
#include "GgaetIp.h"

class Building;
class InfoBox : public Script
{
private:

	Object* _building;

	// �ڽ� ��ü ����
	Transform* _transform;
	Physics* _physics;
	Sprite* _sprite;

	// �ڽ��� �ؽ�Ʈ ����
	Object* _infoText;
	Text* _text;
	map<string, int> _mMaterial;
	map<string, int>::iterator _miMaterial;
	int _time;

	int _numWood;
	int _numStone;
	int _numMud;
	int _numWater;
	int _numGemstone;
	int _numBrick;
	int _numIron;
	int _numPlywood;

	// ��ᰡ 0�� �ƴ� �͸� ���� ���ο� map
	map<string, int> _mValidResources;
	map<string, int>::iterator _miValidResources;



public:
	virtual void Init() override;
	virtual void Update() override;

	//virtual void OnCollisionEnter(Object* obj);
	//virtual void OnCollisionStay(Object* obj);
	//virtual void OnCollisionExit(Object* obj);

	void ShowInfoBox();

	map<string, int> GetMValidResources() { return _mValidResources; }
	map<string, int>::iterator GetMiValidResources() { return _miValidResources; }

	void SetLink(Object* ob) { _building = ob; }
};