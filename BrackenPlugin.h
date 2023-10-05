#ifndef KRAKEN2PLUGIN_H
#define KRAKEN2PLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class BrackenPlugin : public Plugin, Tool
{
public: 
 std::string toString() {return "Bracken";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
//std::map<std::string, std::string> parameters;
 //std::vector<std::string> files;
};

#endif
