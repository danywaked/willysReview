// application.hpp

#pragma once

#include <fstream>
#include <string>
#include "PlayerCharacter.h"
#include "Ball.h"
#include "Wall.h"
#include "Background.h"
#include <string_view>

namespace runner
{
   class Application final
   {
      enum class GameState
      {
          win, lose, running, pregame
      };
      void SetUp();
      bool Update();
      void Render();
      void CollisionCheck();
      void Restart();
      void InputPressed(const sf::Keyboard::Key key);
      void InputRelease(const sf::Keyboard::Key key);
      void LoadHighScore();
      void StoreHighScore();
      bool AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2);
      sf::Text SetText(std::string textSentence, int size, sf::Vector2f position);
      sf::Font m_font;
    
      sf::RenderWindow m_window;
      bool             m_running = true;
      sf::Clock        m_clock;
      sf::Time         m_deltatime;

      Player           m_player = Player("assets/player.png");
      Ball             m_ball = Ball("assets/Ball.png");
      Wall             m_wall = Wall("assets/WhiteHitBrick.png");
      Background       m_background = Background("assets/FallingStar.png");
      GameState        m_currentGameState;

      sf::Text m_startMainuText;
      sf::Text m_winText; 
      sf::Text m_loseText;
      sf::Text m_scoreText;
      sf::Text m_highScoreText;
      int m_highScore;
      int m_currentScore;
      float m_minOfScreen;
      //Keep the state through enum instead of bool

   public:
       Application() ;
       void Run();
   };
} // !runner
