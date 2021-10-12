#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");
    sf::Texture texture;
    texture.loadFromFile("zombie2.gif");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(200.f, 100.f);
    sprite.scale(0.5f, 0.5f);
    sprite.setOrigin(150, 200);

    bool lookRight = true;
    bool rotateDone = false;

    bool right, left = false;


    float speed = 2.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Right)
                {
                    right = true;
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    left = true;
                }

                if(event.key.code == sf::Keyboard::Space)
                {
                    if(!rotateDone)
                    {
                        if(lookRight)
                            sprite.rotate(270);
                        if(!lookRight)
                            sprite.rotate(90);
                        rotateDone = true;
                    }
                }
            }

            if(event.type == sf::Event::KeyReleased)
            {
                right = false;
                left =false;
            }
        }

        if(right)
                {
                    sprite.move(speed, 0.f);
                    if(!lookRight)
                    {
                        sprite.scale(-1, 1);
                    }
                    lookRight = true;
                }
                if(left)
                {
                    sprite.move(-speed, 0.f);
                    if(lookRight)
                    {
                        sprite.scale(-1, 1);
                    }

                    lookRight = false;
                }

        if(rotateDone)
        {
            sprite.move(0.f, 0.5f);
        }


        window.clear(sf::Color::Blue);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
