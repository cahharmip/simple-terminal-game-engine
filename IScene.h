#pragma once

class IScene
{
public:
	virtual ~IScene() = default;
	virtual void Init() = 0;
	virtual void Update(float deltatime) = 0;
	virtual void Draw(float deltatime) = 0;
	virtual void Dispose() = 0;
};