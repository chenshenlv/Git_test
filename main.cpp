#include <iostream> 
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;
struct Pt{ double x, y, z; };

int main() {
ifstream ifs("solver_config.json",iostream::binary);
Json::CharReaderBuilder builder;
builder["collectComments"]=true;
JSONCPP_STRING errs;
// Json::Reader reader;
Json::Value obj;
// ifs>>obj;
// 



if (!parseFromStream(builder, ifs, &obj, &errs)) {
cout << errs << endl;
return EXIT_FAILURE;
}
cout<<"Sound type: "<< obj["Sound"]["type"].asString()<<endl;
cout<<"Sound strength: "<<obj["Sound"]["strength"].asDouble()<<endl;

Pt sound_location;
sound_location.x = obj["Sound"]["location"][0].asDouble();
sound_location.y = obj["Sound"]["location"][1].asDouble();
sound_location.z = obj["Sound"]["location"][2].asDouble();
cout<<"Sound location: ["<< sound_location.x<<","<<sound_location.y<<","<<sound_location.z<<"]"<<endl;

int eval_num;
eval_num = obj["Sound"]["evaluation_point"].size();
Pt* evaluation_point = (Pt*)calloc(eval_num , sizeof(Pt));
for(unsigned i =0; i<obj["Sound"]["evaluation point"].size(); i++)
{
    evaluation_point[i].x = obj["Sound"]["evaluation point"][i][0].asDouble();
    evaluation_point[i].y = obj["Sound"]["evaluation point"][i][1].asDouble();
    evaluation_point[i].z = obj["Sound"]["evaluation point"][i][2].asDouble();
    
}
cout<<"Sound evaluation point: ["<<evaluation_point[1].x<<","<<evaluation_point[1].y<<","<<evaluation_point[1].z<<"]"<<endl;
cout<<"Sound source frequncy start: "<<obj["Sound"]["frequency"][0].asString()<< endl;
cout<<"Sound source frequncy interval: "<<obj["Sound"]["frequency"][1].asString()<<endl;
cout<<"Sound source frequncy end: "<<obj["Sound"]["frequency"][2].asString()<<endl;
cout<<"Mesh path:"<<obj["Mesh"]["path"].asString()<<endl;
cout<<"Impedance:"<<obj["Mesh"]["impedance"].asString()<<endl;

free(evaluation_point);

return 1;
}