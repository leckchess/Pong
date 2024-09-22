#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//float X_Velocity = 0, Y_Velocity = 0, speed = 5;
// assets
Texture t_player1, t_player2, t_ball, t_bg;
Font font;
SoundBuffer b_hit;
SoundBuffer b_hitwall;
Sound s_hit;
Sound s_hitwall;
Music m_bg;
// shapes
RectangleShape player1, player2, bg;
CircleShape ball;
// movement
float speed = 5;
float player1_velocity = 0, player2_velocity = 0, AI_velocity = 0;
Vector2f ball_velocity = Vector2f(-3, -3);
// scoring
int player1_score = 0, player2_score = 0;
Text player1_text, player2_text;

int loadAssets()
{
	if (font.loadFromFile("Font.ttf") == false)
	{
		return -1;
	}

	if (t_player1.loadFromFile("p1.jpg") == false)
	{
		return -1;
	}

	if (t_player2.loadFromFile("p2.jpg") == false)
	{
		return -1;
	}

	if (t_ball.loadFromFile("ball.png") == false)
	{
		return -1;
	}

	if (t_bg.loadFromFile("bg2.jpg") == false)
	{
		return -1;
	}

	if (b_hit.loadFromFile("hit.ogg") == false)
	{
		return -1;
	}

	if (b_hitwall.loadFromFile("hit2.ogg") == false)
	{
		return -1;
	}

	if (m_bg.openFromFile("bg.ogg") == false)
	{
		return -1;
	}

	return 1;
}

void CreateShapes()
{
	// bg
	bg.setSize(Vector2f(800, 600));
	bg.setPosition(0, 0);
	bg.setTexture(&t_bg);

	// player1
	player1.setSize(Vector2f(50, 100));
	player1.setPosition(50, 200);
	player1.setTexture(&t_player1);

	// player2
	player2.setSize(Vector2f(50, 100));
	player2.setPosition(700, 200);
	player2.setTexture(&t_player2);

	// ball
	ball.setRadius(20);
	ball.setPosition(400, 300);
	ball.setTexture(&t_ball);

	// sound
	s_hit.setBuffer(b_hit);
	s_hitwall.setBuffer(b_hitwall);

	// text
	player1_text.setFont(font);
	player1_text.setPosition(50, 50);

	player2_text.setFont(font);
	player2_text.setPosition(600, 50);
}

int main()
{
	RenderWindow win(VideoMode(800, 600), "Game");
	win.setFramerateLimit(60);

	/*
	#pragma region rectangle
		// create rectangle shape
		RectangleShape rect(Vector2f(50, 50));
		rect.setPosition(400, 300);
		rect.setFillColor(Color::Green);

		RectangleShape collision_rect(Vector2f(50, 300));
		collision_rect.setPosition(100, 100);
		collision_rect.setFillColor(Color::Red);

	#pragma endregion
	*/

	cout << "Game Started" << endl;

	// load assets 
	if (loadAssets() == -1)
	{
		return -1;
	}

	cout << "Assets are loaded successfully" << endl;

	// start bg music
	m_bg.play();
	m_bg.setLoop(true);

	// create shapes
	CreateShapes();

	while (win.isOpen())
	{
		Event event;
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				win.close();
			}
		}

		// logic
		/*X_Velocity = 0;
		Y_Velocity = 0;

		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			rect.rotate(1.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			X_Velocity = -speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			X_Velocity = speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
			Y_Velocity = -speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
		{
			Y_Velocity = speed;
		}

		rect.move(X_Velocity, 0);

		// check collision
		if (rect.getGlobalBounds().intersects(collision_rect.getGlobalBounds()))
		{
			rect.move(-X_Velocity, 0);
		}

		rect.move(0, Y_Velocity);

		// check collision
		if (rect.getGlobalBounds().intersects(collision_rect.getGlobalBounds()))
		{
			rect.move(0, -Y_Velocity);
		}*/

#pragma region AI movement

		AI_velocity = 0;
		if (ball.getPosition().y < player2.getPosition().y)
		{
			AI_velocity = -speed;
		}
		if (ball.getPosition().y > player2.getPosition().y)
		{
			AI_velocity = speed;
		}

		player2.move(0, AI_velocity);

		if (player2.getPosition().y < 0 || player2.getPosition().y > 500)
		{
			player2.move(0, -AI_velocity);
		}

#pragma endregion

#pragma region players movement

		player1_velocity = 0;
		player2_velocity = 0;

		/*if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player2_velocity = -speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			player2_velocity = speed;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Down))
		{
			player2_velocity = 0;
		}*/

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player1_velocity = -speed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player1_velocity = speed;
		}

		if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::S))
		{
			player1_velocity = 0;
		}

		player1.move(0, player1_velocity);
		//player2.move(0, AI_velocity);

		// boundries checks
		if (player1.getPosition().y < 0 || player1.getPosition().y > 500)
		{
			player1.move(0, -player1_velocity);
		}

		/*if (player2.getPosition().y < 0 || player2.getPosition().y > 500)
		{
			player2.move(0, -AI_velocity);
		}*/
#pragma endregion

#pragma region ball movement

		ball.move(ball_velocity);

		// check boundies
		if (ball.getPosition().x < 0 || ball.getPosition().x > 760)
		{
			ball_velocity.x *= -1;
			s_hitwall.play();
		}
		if (ball.getPosition().y < 0 || ball.getPosition().y > 560)
		{
			ball_velocity.y *= -1;
			s_hitwall.play();
		}

#pragma endregion

#pragma region Scoring

		if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()))
		{
			ball_velocity.x *= -1;
			if (ball.getPosition().x > player1.getPosition().x + 45)
			{
				player1_score++;
				cout << "player1 score : " << player1_score << " player2 score" << player2_score << endl;
				s_hit.play();
			}
		}

		if (ball.getGlobalBounds().intersects(player2.getGlobalBounds()))
		{
			ball_velocity.x *= -1;
			if (ball.getPosition().x > player1.getPosition().x - 5)
			{
				player2_score++;
				cout << "player1 score: " << player1_score << " player2 score: " << player2_score << endl;
				s_hit.play();
			}
		}

#pragma endregion

#pragma region UI

		player1_text.setString("Player1: " + to_string(player1_score));
		player2_text.setString("Player2: " + to_string(player2_score));

#pragma endregion


		// clear the screen
		win.clear();

		// draw
		/*win.draw(rect);
		win.draw(collision_rect);*/
		//win.draw(bg);
		win.draw(player1);
		win.draw(player2);
		win.draw(ball);
		win.draw(player1_text);
		win.draw(player2_text);

		// display the window
		win.display();
	}

	return 0;
}