#include "graph.h"

Graph::~Graph() {
    delete chartView;

    delete chart;

    delete axisY;
}