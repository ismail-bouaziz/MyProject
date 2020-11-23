//
// Created by alro on 21‏/11‏/2020.
//

#ifndef MYPROJECT_MEDIADISPLAY_H
#define MYPROJECT_MEDIADISPLAY_H

#include <memory>
#include <Entity/Playabale.h>
#include <Entity/Parameter.h>
using namespace std;

class MediaDisplay {
private:
    unique_ptr<Playabale> playabale;
    unique_ptr<Parameter> parameter;

public:
    MediaDisplay( unique_ptr<Playabale> playabale,  unique_ptr<Parameter> parameter);


    const unique_ptr<Playabale> &getPlayabale() const;

    const unique_ptr<Parameter> &getParameter() const;
};


#endif //MYPROJECT_MEDIADISPLAY_H
