#ifndef DEPARTEMENTSCONTROLLER_H
#define DEPARTEMENTSCONTROLLER_H
#include <model/employee/departementsModel.h>
#include "controller/employee/error.h"

class departementsController
{


    public:
    Error validateModel(departementsModel departementsmodel);

};

#endif // DEPARTEMENTSCONTROLLER_H
