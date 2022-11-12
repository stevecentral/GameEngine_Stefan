#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color colour, std::string text)
{
    /*bPressed = false;
    bClicked = false;
    bReleased = false;
    bHighlighted = false;*/
    //std::memset(this, false, sizeof(Button));
    this->bPressed = false;
    this->bReleased = false;
    this->bClicked = false;
    this->bHighlighted = false;

    this->defaultColour = colour;
    this->highlightedColour = sf::Color(this->defaultColour.r + 50, this->defaultColour.g + 50, this->defaultColour.b + 50, this->defaultColour.a);
    this->buttonBG.setSize(size);
    this->buttonBG.setFillColor(defaultColour);
    this->buttonBG.setPosition(sf::Vector2f(0, 0));
    this->buttonText.setCharacterSize(11);
    this->buttonText.setFillColor(sf::Color::White);
    this->buttonText.setPosition(sf::Vector2f(0, 0));
    this->buttonText.setString(text);
}

bool Button::isHighlighted()
{
    return bHighlighted;
}

void Button::HighlightButton(sf::RenderWindow* window)
{
    this->bHighlighted = this->buttonBG.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));

    if (bHighlighted == true) {
        this->buttonBG.setFillColor(this->highlightedColour);
    }
}

void Button::Update(sf::Event event, float deltaTime)
{
    this->CheckPressed(event);
}

void Button::Render(sf::RenderWindow* window, float deltaTime)
{
    window->draw(this->buttonBG);
    window->draw(this->buttonText);
    window->display();
}

void Button::CheckPressed(sf::Event event)
{
    if (! this->bHighlighted) {
        return;
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        this->bPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if (! this->bPressed) {
            this->bClicked = false;
        }
    }

    if (this->bPressed) {
        if (event.type == sf::Event::MouseButtonReleased) {
            this->bReleased = true;
            this->bClicked = true;
        }
    }
    else {
        this->bReleased = false;
        this->bClicked = false;
    }
}
