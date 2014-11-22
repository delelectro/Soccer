#include "params.hpp"

void defaultParams(params & p)
{
   for(int i=0; i<param::END; i++)
      p[i] = 2;

   p[Resize] = PARAM_MAX/2;

   /* inRange terrain */
   p[BgAvgR] = 40;
   p[BgAvgG] = 160;
   p[BgAvgB] = 40;

   p[BgStdDevR] = 10;
   p[BgStdDevG] = 20;
   p[BgStdDevB] = 10;

   p[BgStdDevCoef] = PARAM_MAX/2;


   /* inRange balle */
   p[BallAvgR] = 180;
   p[BallAvgG] = 40;
   p[BallAvgB] = 40;

   p[BallStdDevR] = 10;
   p[BallStdDevG] = 10;
   p[BallStdDevB] = 10;

   p[BallStdDevCoef] = PARAM_MAX/2;


   /* Dilate/Erode Terrain */
   p[BgDilateIterations] = 5;
   p[BgErodeIterations]  = 1;
   p[BgErodeSize] = 5;
   p[BgDilateSize] = 10;
}

std::string to_string(const params & p)
{
   std::string res;
   res.reserve(param::END*3);

   for(int i=0; i<param::END; i++)
      res += std::to_string(p[i]) + ";";

   return std::move(res);
}

bool readParams(params & p, const std::string & str)
{
   std::string n;
   n.reserve(7);
   
   int i = 0;

   for(const auto & c : str)
   {
      if (c != ';')
	 n += c;
      else
      {
	 p[i] = std::stoi(n);
	 i++;
	 n.clear();

	 if (i == param::END)
	    return true;
      }
   }

   defaultParams(p);
   return false;
}