#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BrackenPlugin.h"

void BrackenPlugin::input(std::string file) {
  inputfile = file;
 /*std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   //std::string key, value;
   //ifile >> key;
   //ifile >> value;
   //parameters[key] = value;
	 std::string key;
   ifile >> key;
   if (key != "")
   files.push_back(key);
 }*/
  readParameterFile(file);
}

void BrackenPlugin::run() {
   
}

void BrackenPlugin::output(std::string file) {
	//kraken2 --use-names --db ${KRAKEN2_DB} --paired --output taxa.krak2 R1.fastq R2.fastq
	//trim_galore --no_report_file --paired -o $out $reads_1 $reads_2
	//std::string command = "kraken2 --use-names --db ${KRAKEN2_DB} --output "+file+" "+std::string(PluginManager::prefix())+"/"+parameters["forward"]+" "+std::string(PluginManager::prefix())+"/"+parameters["reverse"];
	//if (parameters.count("assembly") != 0) {
        //   command += " " + std::string(PluginManager::prefix())+"/"+parameters["assembly"];
	//}
//--db $DB_PATH --report-zero-counts --threads $THREADS --report $KRAKEN_REPORT --paired $M1 $M2 > $KRAKEN_OUT
        std::string command = "bracken -d "+myParameters["database"];
	command += " -i "+PluginManager::addPrefix(myParameters["report"]);
	command += " -o "+file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<BrackenPlugin> BrackenPluginProxy = PluginProxy<BrackenPlugin>("Bracken", PluginManager::getInstance());
