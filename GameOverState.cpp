#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Games.hpp"

#include <iostream>

namespace Quizma
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over", GAME_OVER_IMAGE);
		this->_data->assets.LoadTexture("Quit Image", QUIT_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);


		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_gameOver.setPosition((SCREEN_WIDTH / 2) - (_gameOver.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_gameOver.getGlobalBounds().height / 2));

		_nextPage.setTexture(this->_data->assets.GetTexture("Next Page Image"));
		_gameOver.setTexture(this->_data->assets.GetTexture("Game Over"));
		_Quit.setTexture(this->_data->assets.GetTexture("Quit Image"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));

		_cursor.setPosition((SCREEN_WIDTH / 2) - (_cursor.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_cursor.getGlobalBounds().height / 2));
		_cursor.setScale(0.35, 0.35);

		_nextPage.setPosition(1500, 950);
		_Quit.setPosition(1700, 950);

	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			// For moving to the main menu
			if (this->_data->input.IsSpriteClicked(this->_nextPage, sf::Mouse::Left, this->_data->window))
			{
				// Go to the next page/question
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

			//for exiting 
			if (this->_data->input.IsSpriteClicked(this->_Quit, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				//show the game over state!
				//this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				_data->window.close();
			}

			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));

		}
	}

	void GameOverState::Update(float dt)
	{
		//if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		//{
		//	// Close the application
		//	this->_data->window.close();
		//}
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_gameOver);
		this->_data->window.draw(this->_nextPage);
		this->_data->window.draw(this->_Quit);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}
}