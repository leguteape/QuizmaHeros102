#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "Options.hpp"
#include "MainMenuState.hpp"
#include <iostream>

namespace Quizma
{
	Options::Options(GameDataRef data) : _data(data)
	{

	}

	void Options::Init()
	{
		this->_data->assets.LoadTexture("Game Background", OPTONS_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Sound", SOUND_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Song 1", NEXT_MUSIC_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Song 2", NEXT_MUSIC_1_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Option 1 Image", MUSIC_ON);
		this->_data->assets.LoadTexture("Option 2 Image", MUSIC_OFF);
		this->_data->assets.LoadTexture("Option Back", OPTIONS_BACK);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_sound.setTexture(this->_data->assets.GetTexture("Sound"));
		_music1.setTexture(this->_data->assets.GetTexture("Song 1"));
		_music2.setTexture(this->_data->assets.GetTexture("Song 2"));
		_option_1.setTexture(this->_data->assets.GetTexture("Option 1 Image"));
		_option_2.setTexture(this->_data->assets.GetTexture("Option 2 Image"));
		_option_back.setTexture(this->_data->assets.GetTexture("Option Back"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));

		_sound.setPosition(100, 150);
		_music1.setPosition(100, 400);
		_music2.setPosition(100,650);
		_option_1.setPosition(500,150);
		_option_2.setPosition(700,150);
		_option_back.setPosition(1700, 950);

		_cursor.setScale(0.35, 0.35);
	}

	void Options::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
			}

			if (this->_data->input.IsSpriteClicked(this->_option_1, sf::Mouse::Left, this->_data->window))
			{
				//First Music Plays!!
				this->_data->music.stop();
				this->_data->music1.play();
				this->_data->music2.stop();
				this->_data->music3.stop();
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();				
			}

			//for music 2
			if (this->_data->input.IsSpriteClicked(this->_music1, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->music.stop();
				this->_data->music1.stop();
				this->_data->music3.stop();
				this->_data->music2.play();
			}			

			//for music 3
			if (this->_data->input.IsSpriteClicked(this->_music2, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->music.stop();
				this->_data->music1.stop();
				this->_data->music2.stop();
				this->_data->music3.play();
			}
			
			else if (this->_data->input.IsSpriteClicked(this->_option_2, sf::Mouse::Left, this->_data->window))
			{
				//Music Stops!!
			
				this->_data->music.stop();
				this->_data->music1.stop();
				this->_data->music2.stop();

				this->_data->music3.stop();
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
			}

			else if (this->_data->input.IsSpriteClicked(this->_option_back, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}

			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
		}
	}

	void Options::Update(float dt)
	{

	}

	void Options::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_sound);
		this->_data->window.draw(this->_music1);
		this->_data->window.draw(this->_option_1);
		this->_data->window.draw(this->_option_2);
		this->_data->window.draw(this->_music2);
		this->_data->window.draw(this->_option_back);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}

}