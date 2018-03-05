#ifndef DICTENTRY_
#define DICTENTRY_
#include <string>

typedef std::string wordType;
class DictEntry
{
private:
    wordType word;
    wordType definition;

public:
    wordType getWord(){return word;}
    void setWord(wordType _word){word = _word;}
    wordType getDef(){return definition;}
    void setDef(wordType _def){definition = _def;}
    bool operator < (const DictEntry &entry) const {
        return (word < entry.word);}
    bool operator > (const DictEntry &entry) const {
        return (word > entry.word);}
    friend std::ostream& operator<<(std::ostream& out, DictEntry& entry){
      wordType spacer = ": ";
      out << entry.getWord() << spacer << entry.getDef();
      return out;
    }

    DictEntry(std::string _word, std::string _def): word(_word), definition(_def)
    {   }

};

#endif
