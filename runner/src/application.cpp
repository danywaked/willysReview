// application.cpp

#include "application.hpp"
#include <iostream>
namespace runner
{
	bool Application::LoadFontFile(const std::string& filePath) {
		if (m_font.loadFromFile(filePath))
		{
			return true;
		}
		return false;
	}
	sf::Text Application::SetText(std::string textSentence, int size, sf::Vector2f position){
		sf::Text text;
		text.setFont(m_font);
		text.setCharacterSize(size);
		text.setStyle(sf::Text::Bold);
		text.setPosition(position);
		text.setString(textSentence);
		return text;
	}
	void Application::Run()
	{
		const sf::VideoMode mode{ 1280, 720 };
		const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
		m_window.create(mode, "pineapple", flags);
		SetUp();
		if (!m_window.isOpen() ) {
			return;
		}
		m_window.setKeyRepeatEnabled(false);

		while (m_window.isOpen()) {
			sf::Event event;

			while (m_window.pollEvent(event)) {
							
				if (event.type == sf::Event::KeyPressed) {
					InputPressed(event.key.code);
				}
				else if (event.type == sf::Event::KeyReleased)
				{
					InputRelease(event.key.code);
				}
				else if (event.type == sf::Event::Closed) {
					m_window.close();
				}
			}
			if (!Update()) {
				m_window.close();
			}
			Render();
		}
	}

	const void Application::SetUp()
	{
		m_currentGameState = GameState::pregame;

		//m_assetsManagement.LoadFontFile("assets/sunny-spells-font/SunnyspellsRegular-MV9ze.otf");
		if (!m_font.loadFromFile("assets/sunny-spells-font/SunnyspellsRegular-MV9ze.otf"))
		{
			return; //probably shoudl be a throw?
		}

		// Made simple that function that just set indivual each sf::Text variable for text in the screen
		m_startMainuText = SetText("Press `space´ to start", 100, { 250, 250 });
		m_winText = SetText("Winner", 50, { 550, 300 });
		m_loseText = SetText("Game Over", 50, { 550, 300 });
		m_scoreText = SetText("Score", 50, { 1100, 5 });
		m_highScoreText = SetText("", 50, {0, 5});

		m_currentScore = 0;
		m_highScore = 0;
		m_minOfScreen = 0.0f;
		LoadHighScore();

		m_player.SetWorldConstraints(m_minOfScreen, (float)m_window.getSize().x);
		m_ball.SetUp(m_window.getSize().x, m_window.getSize().y, (int)m_minOfScreen, (int)m_minOfScreen);
	}

	bool Application::Update()
	{
		m_deltatime = m_clock.restart();
		if (m_currentGameState == GameState::running)
		{
			m_background.Update(m_deltatime.asSeconds());
			m_scoreText.setString("Score: " + std::to_string(m_currentScore));
			m_player.Update(m_deltatime.asSeconds());
			m_ball.BallUpdate(m_deltatime.asSeconds());
			CollisionCheck();
		}
		else
		{
			m_highScoreText.setString("HighScore: " + std::to_string(m_highScore));
		}

		if (m_wall.brickVec.empty())
		{
			m_currentGameState = GameState::win;
		}
		return m_running;
	}

	const void Application::Render()
	{
		m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });

		if (m_currentGameState == GameState::pregame)
		{
			m_window.draw(m_startMainuText);
		}
		if (m_currentGameState == GameState::running)
		{
			for (int i = 0; i < m_background.stars.size(); i++)
			{
				m_window.draw(m_background.stars[i].sprite);
			}
			m_window.draw(m_scoreText);
			m_window.draw(m_player.sprite);
			m_window.draw(m_ball.ballSprite);
			
			for (int i = 0; i < m_wall.brickVec.size(); i++)
			{
				m_window.draw(m_wall.brickVec[i].sprite);
			}
		}
		if (m_currentGameState == GameState::lose)
		{
			m_window.draw(m_loseText);
			StoreHighScore();
		}
		if (m_currentGameState == GameState::win)
		{
			m_window.draw(m_winText);
			StoreHighScore();
		}
		m_window.draw(m_highScoreText);
		m_window.display();
	}

	void Application::InputPressed(const sf::Keyboard::Key key)
	{
		if (key == sf::Keyboard::Key::Escape) {
			m_running = false;
		}
		m_player.pressedLeft = (key == sf::Keyboard::Key::Left);

		if (key == sf::Keyboard::Right)
		{
			m_player.pressedRight = true;
		}
		else
		{
			m_player.pressedRight = false;
		}

		if (m_currentGameState == GameState::pregame)
		{
			if (key == sf::Keyboard::Key::Space) {
				m_currentGameState = GameState::running;
			}
		}

		if (m_currentGameState == GameState::lose || m_currentGameState == GameState::win)
		{
			if (key == sf::Keyboard::Key::Space) {
				m_currentGameState = GameState::running;
				Restart();
			}
		}
	}

	void Application::InputRelease(const sf::Keyboard::Key key)
	{
		if (key == sf::Keyboard::Right)
		{
			m_player.pressedRight = false;
		}
		if (key == sf::Keyboard::Key::Left)
		{
			m_player.pressedLeft = false;
		}
	}

	void Application::Restart()
	{
		m_currentScore = 0;
		m_ball = Ball();  Restart();
		m_player.Restart();
		m_wall.Restart();
		LoadHighScore();
	}

	void Application::CollisionCheck()
	{
		float r1RightEdge = m_player.sprite.getPosition().y + m_player.sprite.getTexture()->getSize().y;
		if (r1RightEdge >= m_ball.ballSprite.getPosition().y)
		{
			std::cout << " right side someting" << std::endl;
		};
		if (AxisAlignedBoundingBox(m_player.sprite, m_ball.ballSprite))
		{
			m_ball.direction.y *= -1.0f;
			//std::cout << "hitted a player" << std::endl;
		}

		for (int i = 0; i < m_wall.brickVec.size(); i++)
		{
			if (AxisAlignedBoundingBox(m_wall.brickVec[i].sprite, m_ball.ballSprite))
			{
				m_ball.direction.y = -m_ball.direction.y;
				m_ball.speed += 10.0f;
				m_wall.brickVec.erase(m_wall.brickVec.begin() + i);
				m_currentScore++;
				//std::cout << "hitted a brick" << std::endl;
			}
		}
		for (int i = 0; i < m_background.stars.size(); i++)
		{
			if (m_background.stars[i].positionY >= m_window.getSize().y)
			{
				m_background.stars[i].positionY = -100;
			}
		}

		// If the player is out of bounds or edge of the bottom screen that should give trigger fail condition.
		if (m_ball.ballSprite.getPosition().y >= m_window.getSize().y)
		{
			m_currentGameState = GameState::lose;
			//std::cout << "lose" << std::endl;
		}
	}

	void Application::LoadHighScore() {
		std::ifstream readFile;
		readFile.open("assets/HighScore.txt");
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> m_highScore;
			}

		}
		readFile.close();
	};

	void Application::StoreHighScore() {
		if (m_currentScore <= m_highScore)
		{
			return;
		}
		std::ofstream writeFile("assets/HighScore.txt");
		if (writeFile.is_open())	{
			writeFile << m_currentScore;
		}
		writeFile.close();
	}

	bool Application::AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2)
	{
		bool collisionX = box1.getPosition().x + box1.getTexture()->getSize().x >= box2.getPosition().x &&
			box2.getPosition().x + box2.getTexture()->getSize().x >= box1.getPosition().x;

		bool collisionY = box1.getPosition().y + box1.getTexture()->getSize().y >= box2.getPosition().y &&
			box2.getPosition().y + box2.getTexture()->getSize().y >= box1.getPosition().y;
		return collisionX && collisionY;
	}
} // !runner
