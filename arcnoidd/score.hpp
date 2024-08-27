
#include <SFML/Graphics.hpp>


class ScoreDrawable {
public:
    ScoreDrawable();
    void Draw(sf::RenderWindow &window);
    void setScore(int score);
    int getScore() const;
    std::vector<int> readScoresFromDatabase();
  void   addScoreToDatabase();

private:
    sf::Font font;
    sf::Text text;
    int score;

    std::string fontPath;
    sf::Color fontColor;
    sf::Vector2f position;
    unsigned int fontSize;
};