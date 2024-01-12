// application.hpp

#pragma once

#include <fstream>
#include <string>
#include "PlayerCharacter.h"
#include "Ball.h"
#include "Wall.h"
#include "Background.h"

namespace runner
{
   class Application final
   {
      enum class GameState
      {
          win, lose, running, pregame
      };
      const void SetUp();
      bool Update();
      const void Render() ;
      void CollisionCheck();
      void Restart();
      void InputPressed(const sf::Keyboard::Key key);
      void InputRelease(const sf::Keyboard::Key key);
      void LoadHighScore();
      void StoreHighScore();
      bool AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2);
      bool LoadFontFile(const std::string& filePath);
      sf::Text SetText(std::string textSentence, int size, sf::Vector2f position);
      sf::Font m_font;
    
      sf::RenderWindow m_window;
      bool             m_running = true;
      sf::Clock        m_clock;
      sf::Time         m_deltatime;

      Player  m_player;
      Ball             m_ball;
      Wall             m_wall;
      Background       m_background;
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
       Application() = default;
       void Run();
   };
} // !runner
