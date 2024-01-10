// application.hpp

#pragma once

#include <fstream>
#include <string>
#include "batch.hpp"
#include "PlayerCharacter.h"
#include "Ball.h"
#include "Brick.h"
#include "AssetsManagment.h"
#include "ParallaxBackground.h"

namespace runner
{
   class Application final
   {
      enum class TheGamesStates
      {
          win, lose, running, pregame
      };
      enum class TextureName
      {
          Texture_player, Texture_ball, Texture_brick  
      };
      void SetUp();
      bool update();
      void render();
      void CollisionCheck();
      void Restart();
      void on_key_pressed(const sf::Keyboard::Key key);
      void on_key_released(const sf::Keyboard::Key key);
      void loadHighScore();
      void StoreHighScore();
      bool AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2);

      sf::RenderWindow m_window;
      PrimitiveBatch   m_batch;
      bool             m_running = true;
      sf::Clock        m_clock;
      sf::Time         m_deltatime;
      PlayerCharacter  m_player;
      Ball             m_ball;
      Brick            m_brick;
      AssetsManagement m_AssetsManagement;
      TheGamesStates   m_CurrentGameState;
      parallaxBackground m_parallaxBackground;
      sf::Text m_startMainuText, m_WinText, m_LoseText, m_ScoreText, m_highScoreText;
      int m_highScoreInt;
      int m_currentScore;
      float m_minOfScreen;
      //Keep the state through enum instead of bool

   public:
       Application() = default;
       void run();
   };
} // !runner
