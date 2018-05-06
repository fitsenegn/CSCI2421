#ifndef DATACONTAINERS_H_
#define DATACONTAINERS_H_
#include <string>
#include <iostream>
#include <sstream>


std::string stripPunctuation(std::string temp);


//---------------------------ACTOR_ACTRESS------------------------------------------
struct Full_Name
{
  std::string First;
  std::string Last;
};

struct Actor_Actress_temp{
  std::string Compare = "";
  int Year = 0;
  std::string Award = " "; //maybe Enum?
  int Winner = -1; // 0 means they lost 1 means they won
  std::string Name = " ";
  std::string Film = " ";
};


class Actor_Actress //Year,Award,Winner,Name,Film
{
public:
    Actor_Actress_temp _self;

    int userInput();
    int modifyField();

    //SEEETTERS
    void setComp(std::string comp){_self.Compare = comp;};
    void setYear(int year){_self.Year = year;};
    void setAward(std::string award){_self.Award = award;};
    void setWinner(int winner){_self.Winner = winner;};
    void setName(std::string name){
        _self.Name = name;
        setComp(stripPunctuation(name));
      };
    void setFilm(std::string film){_self.Film = film;};

    //GEEETTERS
    std::string getComp(){return _self.Compare;};
    int getYear(){return _self.Year;};
    std::string getAward(){return _self.Award;};
    int getWinner(){return _self.Winner;};
    std::string getName(){return _self.Name;};
    std::string getFilm(){return _self.Film;};

    std::string print() const;

    bool operator>=(Actor_Actress comp){
      return _self.Compare >= comp.getComp();
    }

    bool operator<=(Actor_Actress comp){
      return _self.Compare >= comp.getComp();
    }

    bool operator>(Actor_Actress comp){
      return _self.Compare > comp.getComp();
    }

    bool operator<(Actor_Actress comp){
      return _self.Compare < comp.getComp();
    }

    Actor_Actress(Actor_Actress_temp instantiation): _self(instantiation)
    { this->setName(this->getName());} //set Comparison

    Actor_Actress()
    {Actor_Actress_temp temp;
    this->_self = temp;}

};



//----------------------------------FILM----------------------------------------------

struct Picture_temp{ //name,year,nominations,rating,duration,
                //genre1,genre2,release,metacritic,synopsis
  std::string Compare = "";
  std::string Name = "";
  int Year = -1;
  int Nominations = -1;
  double Rating = -1;
  int Duration = -1;
  std::string Genre1 = "";
  std::string Genre2 = "";
  std::string Release = "";
  int Metacritic = -1;
  std::string Synopsis = "";
};


class Picture{
public:
  Picture_temp _self;

  int userInput();
  int modifyField();

  //SEEEEEEEEEETTERS
  void setComp(std::string comp){_self.Compare = comp;};
  void setName(std::string name){
      _self.Name = name;
      setComp(stripPunctuation(name));
    };
  void setYear(int year){_self.Year = year;};
  void setNom(int nominations){_self.Nominations = nominations;};
  void setRating(double rating){_self.Rating = rating;};
  void setDuration(int duration){_self.Duration = duration;};
  void setGenre1(std::string genre1){_self.Genre1 = genre1;};
  void setGenre2(std::string genre2){_self.Genre2 = genre2;};
  void setRelease(std::string release){_self.Release = release;};
  void setMetacritic(int metacritic){_self.Metacritic = metacritic;};
  void setSynopsis(std::string synopsis){_self.Synopsis = synopsis;};

  //GEEEEEEEEEETTERS
  std::string getComp(){return _self.Compare;};
  std::string getName(){return _self.Name;};
  int getYear(){return _self.Year;};
  int getNom(){return _self.Nominations;};
  double getRating(){return _self.Rating;};
  int getDuration(){return _self.Duration;};
  std::string getGenre1(){return _self.Genre1;};
  std::string getGenre2(){return _self.Genre2;};
  std::string getRelease(){return _self.Release;};
  int getMetacritic(){return _self.Metacritic;};
  std::string getSynopsis(){return _self.Synopsis;};





  bool operator>=(Picture comp){
    return _self.Compare >= comp.getComp();
  }

  bool operator<=(Picture comp){
    return _self.Compare >= comp.getComp();
  }

  bool operator>(Picture comp){
    return _self.Compare > comp.getComp();
  }

  bool operator<(Picture comp){
    return _self.Compare < comp.getComp();
  }


  std::string print() const; //this will return a formatted string for printing

  Picture(Picture_temp instantiation): _self(instantiation)
  {this->setName(this->getName());} //set Comparison

  Picture(){
    Picture_temp temp;
    this->_self = temp;
  };

};

#endif
