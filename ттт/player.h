#pragma once
#include "settings.h"
#include "game_obj.h"

class Player :public GameObject {
private:
	float speed = 0,speedx= 0,speedy = 0; 
	int hp = 100; 
	bool onGround = false;

	float dv = 0.1f;
	float maxSpeed = 10.f;
	float gravity = 10.f;
	bool jump = false;

public:
	Player();
	void update();
	void draw(sf::RenderWindow& window);
	void jump();
};

Player::Player() {
	texture.loadFromFile(PlayerFileName);
	sprite.setTexture(texture);
	sf::FloatRect bounds = sprite.getLocalBounds();
	//sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	sprite.setPosition(PlayerStartPos);
	
}

//bool Player::onGround() {};

void Player::update() {
	//�������� ���������
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//�����
		speedx = -maxSpeed;
		sprite.move(speedx, speedy);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//������
		speedx = maxSpeed;
		sprite.move(speedx, speedy);
	}
	
	sf::FloatRect bounds = sprite.getLocalBounds();
	sf::Vector2f pos = sprite.getPosition();
	
	//sprite.move(speedx, speedy);
	if (speed < 0) speed = 0.f;
	else if (speed > maxSpeed) speed = maxSpeed;
	
	//����������
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (onGround)) {
		sprite.move(0, -200.f-gravity);
		onGround = false;
	}
	
	if (onGround == false) {
		sprite.move(0, gravity);
	}
	//������
	

	////������� ������
	//����
	if (pos.x <= 0) {
		sprite.setPosition(0 , pos.y);
	}
	//����� 
	if (pos.x >= WINDOW_WIDTH) {
		sprite.setPosition(WINDOW_WIDTH ,pos.y);
	}
	//���
	if (pos.y + bounds.height/2 >= WINDOW_HEIGHT) {
		onGround = true;
		sprite.setPosition(pos.x,WINDOW_HEIGHT-bounds.height);
	}
};


void Player::draw(sf::RenderWindow& window) { window.draw(sprite); };

void Player::jump() {
	sprite.move(0, );
}