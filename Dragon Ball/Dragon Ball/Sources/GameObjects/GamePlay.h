#pragma once
#include<SFML/Graphics.hpp>
#include"../GameConfig.h"
#include"Background/Layer.h"
class GamePlay
{
public:
	GamePlay();
	virtual ~GamePlay();
	void Exit();
	void Pause();
	void Resume();
	void Run(float deltatime,sf::RenderWindow* window);


	void Init();
	void Update(float m_deltatime);
	void Render(sf::RenderWindow* window);
	
private:
	Layer m_bg;
};