
#include "score.hpp"
#include <iostream>
#include <sqlite3.h>

ScoreDrawable::ScoreDrawable() 
    : score(0), fontPath("Pacifico.ttf"), fontColor(sf::Color::White), position(sf::Vector2f(10, 10)), fontSize(24) {
    
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font: " << fontPath << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(fontColor);
    text.setPosition(position);
}

void ScoreDrawable::Draw(sf::RenderWindow &window) {
    text.setString("Score: " + std::to_string(score));
    window.draw(text);
}

void ScoreDrawable::setScore(int newScore) {
    score = newScore;
}

int ScoreDrawable::getScore() const {
    return score;
}
void ScoreDrawable::addScoreToDatabase() {
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;

        rc = sqlite3_open("scores.db", &db);

        if( rc ) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            return;
        } else {
            std::cout << "Opened database successfully\\n";
        }

        std::string sql = "INSERT INTO scores (score) VALUES (" + std::to_string(score) + ");";
        rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    
        if( rc != SQLITE_OK ){
            std::cerr << "SQL error: " << zErrMsg << std::endl;
            sqlite3_free(zErrMsg);
        } else {
            std::cout << "Score added successfully\\n";
        }
        sqlite3_close(db);
    }

     std::vector<int> ScoreDrawable:: readScoresFromDatabase() {
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        std::vector<int> scores;

        rc = sqlite3_open("scores.db", &db);

        if(rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            return scores;
        }

        const char* sql = "SELECT score FROM scores;";
        sqlite3_stmt *stmt;
        
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                int score = sqlite3_column_int(stmt, 0);
                scores.push_back(score);
            }
        } else {
            std::cerr << "Failed to execute query: " << sqlite3_errmsg(db) << std::endl;
        }

        sqlite3_finalize(stmt);
        sqlite3_close(db);

        return scores;
    }