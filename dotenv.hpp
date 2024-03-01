#ifndef DOTENV_HPP
#define DOTENV_HPP

#include <iostream>
#include <string>
#include <fstream>

std::string obtainEnv(std::string line, std::string env, char seperator);
static void splitLine(std::string line, std::string& env, std::string& value, char seperator);

std::string obtainEnv(std::string fileName, std::string env, char seperator = '=') {
    for (int i = 0; i <= env.size(); i++) {
        if (env[i] == seperator) {
            throw std::runtime_error("Env can not contain seperator.");
        }
    }

    std::string text;
    std::string tempEnv;
    std::string value;
    std::ifstream envFile(fileName);

    if (!envFile) {
        throw std::runtime_error("Failed to open file: " + fileName);
    }

    while (std::getline (envFile, text)) {
        splitLine(text, tempEnv, value, seperator);
        if (tempEnv == env) {
            envFile.close();
            return value;
        }
    }

    envFile.close();

    return "";
}

static void splitLine(std::string line, std::string& env, std::string& value, char seperator) {
    bool reachedSeperator = false;
    env.clear();
    value.clear();

    for (int i = 0; i <= line.size(); i++)
    {
        if (!reachedSeperator) {
            if (line[i] == seperator) {
                reachedSeperator = true;
            }
            
            else {
                env += line[i];
            }
        }

        else {
            value += line[i];
        }
    }
}

#endif
