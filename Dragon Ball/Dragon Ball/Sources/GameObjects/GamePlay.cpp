#include "GamePlay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::Exit()
{
}

void GamePlay::Pause()
{
}

void GamePlay::Resume()
{
}


void GamePlay::Init()
{
	printf("play game");
	m_bg.Init("/Background layers/background");
}

void GamePlay::Update(float m_deltatime)
{
	m_bg.Update(m_deltatime);
}

void GamePlay::Render(sf::RenderWindow* window)
{
	m_bg.Render(window);
}
void GamePlay::Run(float deltatime, sf::RenderWindow
	* window)
{

	Init();
	Update(deltatime);
	Render(window);
}

