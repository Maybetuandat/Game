#include "GSMenu.h"
GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::DrawBg()
{
	//set background 
	m_background.setSize(Vector2f(screenWidth, screenHeight));
	m_Maintexture.loadFromFile("../Data/Textures/Background layers/background.png");
	m_background.setTexture(&m_Maintexture);

	

	//photo in options
	Obackground.setSize(Vector2f(screenWidth, screenHeight));
	Op_texture.loadFromFile("../Data/Textures/Background layers/background.png");
	Obackground.setTexture(&Op_texture);


	//pho to in the Abouts
	Abackground.setSize(Vector2f(screenWidth, screenHeight));
	About_texture.loadFromFile("../Data/Textures/Background layers/background.png");
	Abackground.setTexture(&About_texture);
};
void GSMenu::Update(float deltatime)
{
	m_currentime += deltatime;
}

void GSMenu:: Run()
{
	RenderWindow MENU(VideoMode(screenWidth, screenHeight), titleGame, sf::Style::Default);
	MainMenu mainMenu(screenWidth, screenHeight);
	DrawBg();
	GamePlay game;
	sf::Clock clock;

	float deltatime = 0.f;
	
	while (MENU.isOpen())
	{
		sf::Event event;
		deltatime = clock.restart().asSeconds();
		while (MENU.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				MENU.close();

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
				}
				if (event.key.code == Keyboard::Return)
				{
					RenderWindow Play(VideoMode(screenWidth, screenHeight), "Dragon Ball");
					RenderWindow OPTIONS(VideoMode(screenWidth, screenHeight), "Options");
					RenderWindow About(VideoMode(screenWidth, screenHeight), "Abouts");
					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (Play.isOpen())
						{
							Event aevent;
							while (Play.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									Play.close();

								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Play.close();
									}
								}
							}
							OPTIONS.close();
							About.close();
							Play.clear();
							Update(deltatime);
							game.Run(m_currentime, &Play);
							Play.display();
						}
					}
					if (x == 1)
					{

						while (OPTIONS.isOpen())
						{
							Event aevent;
							while (OPTIONS.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									OPTIONS.close();

								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										OPTIONS.close();
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							About.close();
							OPTIONS.draw(Obackground);
							OPTIONS.display();
						}
					}
					if (x == 2)
					{
						while (About.isOpen())
						{
							Event aevent;
							while (About.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
								{
									About.close();

								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										About.close();
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							About.clear();
							About.draw(Abackground);
							About.display();
						}
					}
					if (x == 3)
						MENU.close();
					break;
				}

			}
			MENU.clear();
			MENU.draw(m_background);
			mainMenu.Draw(MENU);
			MENU.display();
		}

	}
}

