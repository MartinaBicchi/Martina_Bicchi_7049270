//
// Created by Martina on 13/07/2021.
//

#include "NotesCollection.h"

void NotesCollection::subscribe(Observer* onew){
    observers.push_back(onew);
}
void NotesCollection::unsubscribe(Observer* old){
    observers.remove(old);
}

void NotesCollection::notify(){
   for(auto itr:observers) {
       itr->update();
   }
}