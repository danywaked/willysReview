// application.cpp

#include "application.hpp"
#include <iostream>
namespace runner
{
	std::string kPlayerID = "player";
	std::string kBallID = "ball";
	std::string kBrickID = "brick";
	std::string kFallingStarID = "fallingStar";

	void Application::run()
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
					on_key_pressed(event.key.code);
				}
				else if (event.type == sf::Event::KeyReleased)
				{
					on_key_released(event.key.code);
				}
				else if (event.type == sf::Event::Closed) {
					m_window.close();
				}
			}

			if (!update()) {
				m_window.close();
			}
			render();
		}
	}

	void Application::SetUp()
	{
		m_CurrentGameState = GameState::pregame;

		//m_AssetsManagement.LoadTexture(kPlayerID, "assets/player.png");
		//m_AssetsManagement.LoadTexture(kBallID, "assets/Ball.png");
		//m_AssetsManagement.LoadTexture(kBrickID, "assets/WhiteHitBrick.png");
		//m_AssetsManagement.LoadTexture(kFallingStarID, "assets/FallingStar.png");
		m_AssetsManagement.LoadFontFile("assets/sunny-spells-font/SunnyspellsRegular-MV9ze.otf");
		if (!m_font.loadFromFile("assets/sunny-spells-font/SunnyspellsRegular-MV9ze.otf"))
		{
			printf("Font did not load!");
		}

		// Made simple that function that just set indivual each sf::Text variable for text in the screen
		m_startMainuText = m_AssetsManagement.SetText("Press `space� to start", 100, sf::Text::Bold, 250, 250);
		m_winText = m_AssetsManagement.SetText("Winner", 50, sf::Text::Bold, 550, 300);
		m_loseText = m_AssetsManagement.SetText("Game Over", 50, sf::Text::Bold, 550, 300);
		m_scoreText = m_AssetsManagement.SetText("Score", 50, sf::Text::Bold, 1100, 5);
		m_highScoreText = m_AssetsManagement.SetText("", 50, sf::Text::Bold, 0, 5);

		m_currentScore = 0;
		m_highScore = 0;
		m_minOfScreen = 0.0f;
		loadHighScore();

		m_player.SetWorldConstraints(m_minOfScreen, (float)m_window.getSize().x);
		m_ball.SetUp(m_window.getSize().x, m_window.getSize().y, (int)m_minOfScreen, (int)m_minOfScreen);
		//m_wall.SetUp();
		m_background.SetUp();
	}

	bool Application::update()
	{
		m_deltatime = m_clock.restart();
		if (m_CurrentGameState == GameState::running)
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
			m_CurrentGameState = GameState::win;
		}
		return m_running;
	}

	void Application::render()
	{
		m_batch.clear();
		m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });

		if (m_CurrentGameState == GameState::pregame)
		{
			m_window.draw(m_startMainuText);
		}

		if (m_CurrentGameState == GameState::running)
		{
			for (int i = 0; i < m_background.m_fallingStarYellow.size(); i++)
			{
				m_window.draw(m_background.m_fallingStarYellow[i].sprite);
			}
			for (int i = 0; i < m_background.m_fallingStarRed.size(); i++)
			{
				m_window.draw(m_background.m_fallingStarRed[i].sprite);
			}
			m_window.draw(m_scoreText);
			m_window.draw(m_player.sprite);
			m_window.draw(m_ball.ballSprite);

			for (int i = 0; i < m_wall.brickVec.size(); i++)
			{
				m_window.draw(m_wall.brickVec[i].sprite);
			}
		}

		if (m_CurrentGameState == GameState::lose)
		{
			m_window.draw(m_loseText);
			StoreHighScore();
		}

		if (m_CurrentGameState == GameState::win)
		{
			m_window.draw(m_winText);
			StoreHighScore();
		}

		m_window.draw(m_highScoreText);

		m_batch.present(m_window);
		m_window.display();
	}

	void Application::on_key_pressed(const sf::Keyboard::Key key)
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

		if (m_CurrentGameState == GameState::pregame)
		{
			if (key == sf::Keyboard::Key::Space) {
				m_CurrentGameState = GameState::running;
			}
		}

		if (m_CurrentGameState == GameState::lose || m_CurrentGameState == GameState::win)
		{
			if (key == sf::Keyboard::Key::Space) {
				m_CurrentGameState = GameState::running;
				Restart();
			}
		}
	}

	void Application::on_key_released(const sf::Keyboard::Key key)
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
		m_ball.Restart();
		m_player.Restart();
		m_wall.Restart();
		loadHighScore();
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
			m_ball.direction.y = -m_ball.direction.y;
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
		for (int i = 0; i < m_background.m_fallingStarYellow.size(); i++)
		{
			if (m_background.m_fallingStarYellow[i].positionY >= m_window.getSize().y)
			{
				m_background.m_fallingStarYellow[i].positionY = -100;
			}
		}
		for (int i = 0; i < m_background.m_fallingStarRed.size(); i++)
		{
			if (m_background.m_fallingStarRed[i].positionY >= m_window.getSize().y)
			{
				m_background.m_fallingStarRed[i].positionY = -100;
			}
		}
		// If the player is out of bounds or edge of the bottom screen that should give trigger fail condition.
		if (m_ball.ballSprite.getPosition().y >= m_window.getSize().y)
		{
			m_CurrentGameState = GameState::lose;
			//std::cout << "lose" << std::endl;
		}
	}

	void Application::loadHighScore() {
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
