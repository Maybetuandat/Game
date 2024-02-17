#include"GameObjects/GSMenu.h"
class Application
{
public:
	void Run();
private:
	void Init();
	void Update(float deltatime);
	void Render();
	sf::RenderWindow* m_window;
	sf::Sprite m_sprite;
};