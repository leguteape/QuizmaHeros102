#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "HighScore.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	HighScore::HighScore(GameDataRef data) : _data(data)
	{

	}

	void HighScore::Init()
	{
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Again", PLAY_AGAIN_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Quit Image", QUIT_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_playAgain.setTexture(this->_data->assets.GetTexture("Play Again"));
		_Quit.setTexture(this->_data->assets.GetTexture("Quit Image"));
	
		_playAgain.setPosition(1300, 950);
		_Quit.setPosition(1700, 950);


		_optionsBox1.setColor(sf::Color::Black);
		_optionsBox2.setColor(sf::Color::Black);
		_optionsBox3.setColor(sf::Color::Black);
		_optionsBox4.setColor(sf::Color::Black);
	}

	void HighScore::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			
			if (this->_data->input.IsSpriteClicked(this->_playAgain, sf::Mouse::Left, this->_data->window))
			{

				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_Quit, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}

		
		}
	}

	void HighScore::Update(float dt)
	{

	}

	void HighScore::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playAgain);
		this->_data->window.draw(this->_Quit);

		this->_data->window.display();
	}


}