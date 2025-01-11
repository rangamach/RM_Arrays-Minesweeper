#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		FLAGGED,
		EXPLOSION,
		COMPLETED,
	};

	class SoundService
	{
	private:
		const int background_music_volume = 30;

		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer buffer_button_click;
		sf::SoundBuffer buffer_flag_sound;
		sf::SoundBuffer buffer_exploding_sound;
		sf::SoundBuffer buffer_completed_sound;

		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();

	public:
		void initialize();

		void playSound(SoundType soundType);
		void playBackgroundMusic();
	};
}