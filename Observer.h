//
// Created by Martina on 13/07/2021.
//

#ifndef MARTINA_BICCHI_7049270_OBSERVER_H
#define MARTINA_BICCHI_7049270_OBSERVER_H


class Observer{
public:
    virtual ~Observer()=default;
    virtual void update()=0;
};
#endif //MARTINA_BICCHI_7049270_OBSERVER_H
