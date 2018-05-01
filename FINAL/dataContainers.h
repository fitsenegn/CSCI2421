#include <string>
#include <iostream>
#include <sstream>


//---------------------------ACTOR_ACTRESS------------------------------------------
struct Full_Name
{
  std::string First;
  std::string Last;
};

struct Actor_Actress_temp{
  int Year = 0;
  std::string Award = " "; //maybe Enum?
  int Winner = -1; // 0 means they lost 1 means they won
  std::string Name = " ";
  std::string Film = " ";
};


struct Actor_Actress //Year,Award,Winner,Name,Film
{
    Actor_Actress_temp _self;

    //SEEETTERS
    void setYear(int year){_self.Year = year;};
    void setAward(std::string award){_self.Award = award;};
    void setWinner(int winner){_self.Winner = winner;};
    void setName(std::string name){_self.Name = name;};
    void setFilm(std::string film){_self.Film = film;};

    //GEEETTERS
    int getYear(){return _self.Year;};
    std::string getAward(){return _self.Award;};
    int getWinner(){return _self.Winner;};
    std::string getName(){return _self.Name;};
    std::string getFilm(){return _self.Film;};

    std::string print() const{ //this will return a formatted string for printing
      std::stringstream out;

      out << "Name:       " << _self.Name;


      out << "\nAward:      " << _self.Award;

      if(_self.Winner == 1){
        out << "\nWinner:     Yes";
      }else if(_self.Winner == 0){
        out << "\nWinner:     No";
      }

      out << "\nFilm:       " << _self.Film;

      out << "\nYear:       " << _self.Year;

      return out.str();

    }

    bool operator>=(Actor_Actress comp){
      return _self.Name >= comp.getName();
    }

    bool operator<=(Actor_Actress comp){
      return _self.Name >= comp.getName();
    }

    bool operator>(Actor_Actress comp){
      return _self.Name > comp.getName();
    }

    bool operator<(Actor_Actress comp){
      return _self.Name < comp.getName();
    }

    Actor_Actress(Actor_Actress_temp instantiation): _self(instantiation)
    { }

    Actor_Actress()
    {Actor_Actress_temp temp;
    this->_self = temp;}

};



//----------------------------------FILM----------------------------------------------

struct Picture_temp{ //name,year,nominations,rating,duration,
                //genre1,genre2,release,metacritic,synopsis
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


struct Picture{
  Picture_temp _self;


  //SEEEEEEEEEETTERS
  void setName(std::string name){_self.Name = name;};
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
    return _self.Name >= comp.getName();
  }

  bool operator<=(Picture comp){
    return _self.Name >= comp.getName();
  }

  bool operator>(Picture comp){
    return _self.Name > comp.getName();
  }

  bool operator<(Picture comp){
    return _self.Name < comp.getName();
  }





  std::string print(){ //this will return a formatted string for printing
    std::stringstream out;

    out << "Name: " << _self.Name;


    out << "\nYear: \n    " << _self.Year;

    out << "\nNominations: \n    " << _self.Nominations;

    out << "\nRating: \n    " << _self.Rating;

    out << "\nDuration: \n    " << _self.Duration;

    out << "\nGenre1: \n    " << _self.Genre1;

    out << "\nGenre2: \n    " << _self.Genre2;

    out << "\nRelease: \n    " << _self.Release;

    out << "\nMetacritic: \n    " << _self.Metacritic;

    out << "\nSynopsis: \n    " << _self.Synopsis;

    return out.str();
  }

  Picture(Picture_temp instantiation): _self(instantiation)
  { }
  Picture(){
    Picture_temp temp;
    this->_self = temp;
  };
};
