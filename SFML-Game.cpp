
/*
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

bool LeftMouseButton_Pressed = false;

int main()
{
	RenderWindow win(VideoMode(800, 600), "SFML WOrks", Style::Titlebar | Style::Close | Style::Resize);
	//win.setVerticalSyncEnabled(true); // force it to work at the refresh rate of the monitor
	win.setFramerateLimit(60); // force it to work at a specific frame rate

	cout << "Game Started" << endl;

#pragma region texture
	Texture tex;
	if (tex.loadFromFile("1.jpg"))
	{
		cout << "image 1 loaded" << endl;
		tex.setSmooth(true);
	}
	else
	{
		cout << "can't load image 1" << endl;
	}

	Texture tex2;
	if (tex2.loadFromFile("2.jpg"))
	{
		cout << "image 2 loaded" << endl;
	}
	else
	{
		cout << "can't load image 2" << endl;
	}

	Texture tex3;
	if (tex3.loadFromFile("3.jpg"))
	{
		cout << "image 3 loaded" << endl;
	}
	else
	{
		cout << "can't load image 3" << endl;
	}

#pragma endregion

#pragma region font

	Font font;
	if (font.loadFromFile("Font.ttf"))
	{
		cout << "Font Loaded" << endl;
	}
	else
	{
		cout << "Failed to load Font" << endl;
	}

#pragma endregion

#pragma region audio

	SoundBuffer sound_buffer;
	if (sound_buffer.loadFromFile("SFX.wav"))
	{
		cout << "Audio Loaded" << endl;
	}
	else
	{
		cout << "Failed to load Audio" << endl;
	}

#pragma endregion

#pragma region rectangle
	// create rectangle shape
	RectangleShape rect(Vector2f(100, 100));
	// change its pivot
	rect.setOrigin(50, 50);
	// set a specific position
	rect.setPosition(400, 300);
	// add texture
	rect.setTexture(&tex);
	// change color
	//rect.setFillColor(Color(50, 50, 200));

#pragma endregion

#pragma region circle
	// create circle shape
	//CircleShape circle(200);
	CircleShape circle(200, 8);
	// change radius
	circle.setRadius(50);
	// change color
	//circle.setFillColor(Color(100, 50, 50));
	// outline
	circle.setOutlineThickness(5);
	// change outline color
	circle.setOutlineColor(Color(0, 0, 0));
	// add texture
	circle.setTexture(&tex2);

#pragma endregion

#pragma region sprite

	Sprite spr;
	spr.setTexture(tex3);
	spr.setScale(0.25f, 0.25f);
	spr.setPosition(250, 150);

#pragma endregion

#pragma region text

	Text text;
	text.setFont(font);
	text.setString("HEHEHEEH...~");
	text.setPosition(300, 50);
	text.setCharacterSize(50);
	text.setFillColor(Color(255, 50, 50));
	text.setStyle(Text::Bold | Text::Italic);

#pragma endregion

#pragma region Sound / SFX
	Sound bg_music;
	bg_music.setBuffer(sound_buffer);
	bg_music.play();
	//bg_music.setLoop(true);
	bg_music.setVolume(100);
	bg_music.setPitch(2);

#pragma endregion

#pragma region Music
	Music music;
	if (music.openFromFile("audio.ogg"))
	{
		cout << "Music Loaded" << endl;
		music.setPlayingOffset(seconds(60)); // idk why it doesnt work - maybe
		music.play();
		music.setLoop(true);
	}
	else
	{
		cout << "Failed to load Music" << endl;
	}

#pragma endregion



	while (win.isOpen())
	{
		Event event;
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				win.close();
			}
#pragma region Events

			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::Up:
					cout << "UP was pressed" << endl;
					cout << event.key.control << endl;
					break;
				default:
					break;
				}
			}

			if (event.type == Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case Keyboard::Up:
					cout << "UP was released" << endl;
					cout << event.key.control << endl;
					break;
				default:
					break;
				}
			}

			if (event.type == Event::MouseButtonPressed)
			{
				switch (event.mouseButton.button)
				{
				case Mouse::Left:
					LeftMouseButton_Pressed = true;
					cout << "Left mouse button was pressed" << endl;
					cout << "X = " << event.mouseButton.x << " ,Y = " << event.mouseButton.y << endl;
					break;
				case Mouse::Right:
					cout << "Left mouse button was pressed" << endl;
					cout << "X = " << event.mouseButton.x << " ,Y = " << event.mouseButton.y << endl;
					break;
				default:
					break;
				}
			}

			if (event.type == Event::MouseButtonReleased)
			{
				switch (event.mouseButton.button)
				{
				case Mouse::Left:
					LeftMouseButton_Pressed = false;
					cout << "Left mouse button was released" << endl;
					break;
				case Mouse::Right:
					cout << "Left mouse button was released" << endl;
					break;
				default:
					break;
				}
			}

			if (event.type == Event::MouseMoved)
			{
				//if (LeftMouseButton_Pressed)
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					cout << "X = " << event.mouseMove.x << " ,Y = " << event.mouseMove.y << endl;
				}
			}
#pragma endregion

		}

		// logic

#pragma region Builtin
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			cout << "Down button is pressed" << endl;
		}

		if (Mouse::isButtonPressed(Mouse::Right))
		{
			cout << "X = " << Mouse::getPosition().x << " ,Y = " << Mouse::getPosition().y << endl;
		}
#pragma endregion

		rect.move(0.2f, 0);
		rect.rotate(1.0f);

		circle.move(0.5f, 0.5f);
		circle.rotate(1.0f);


		// clear the screen
		//win.clear();
		win.clear(Color(0, 125, 125));

		// draw
		win.draw(spr);
		win.draw(rect);
		win.draw(circle);
		win.draw(text);

		// display the window
		win.display();
	}

	return 0;
}
*/