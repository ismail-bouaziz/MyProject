//
// Created by alro on 21‏/11‏/2020.
//

#ifndef MYPROJECT_PARAMETER_H
#define MYPROJECT_PARAMETER_H


class Parameter {
private:
    bool fullscreen;
    int volume;
    int timeout;
    float speed;

public:
    Parameter(bool fullscreen, int volume, int timeout, float speed);

    [[nodiscard]] bool isFullscreen() const;

    [[nodiscard]] int getVolume() const;

    [[nodiscard]] int getTimeout() const;

    [[nodiscard]] float getSpeed() const;
};


#endif //MYPROJECT_PARAMETER_H
