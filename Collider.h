#pragma once
#include "Component.h"
#include "Vector2.h"
#include "Box2D/Box2D.h"

class Transform;
class Physics;

class Collider : public Component
{
protected:
	Transform* transform;
	Physics* physicsComponent;
	b2Body* body;
	b2Fixture* fixture;
	b2Filter filter;
	bool fixedRotation = false;

	bool isColliding = false;

public:
	Collider();
	b2Body* GetBody();

	void OnMouseDown();
	void OnMouse();
	void OnMouseUp();
	void OnMouseExit();

	void SetFilter(b2Filter filter);

	virtual bool PtInCollider(Vector2 point) = 0;
	virtual void Update() override;
	virtual void Init() override;
	virtual void Awake() override;
	virtual void Release() override;

	void SetFixedRotation(bool _fixedRotation) { fixedRotation = _fixedRotation; }
};