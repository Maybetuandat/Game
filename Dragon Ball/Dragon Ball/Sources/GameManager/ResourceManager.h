#include"Singleton.h"
#include<map>
#include<string>
#include<SFML/Graphics.hpp>
#include"../GameObjects/Animation.h"

#define DATA ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);

private:

	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, sf::Font*> m_MapFont;

	std::string m_Path;
	std::string m_TextPath;
	std::string m_FontPath;

};