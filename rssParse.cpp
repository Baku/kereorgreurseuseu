#include "rssParse.h"

rssParse::rssParse(Qstring name):_filename(name)
{
}

rss::~rssParse()
{
}

void	rss::parse()
{
  QFile file(filename_);

  if (file.open(QFile::ReadOnly))
    {
      char buf[1024];
      qint64 lineLength;
      char *split;
      lineLength = file.readLine(buf, sizeof(buf));

      while (lineLength != -1)
	{

	  Qstring tmpString(buf);
	  QstringList eplode(QStringList::split(" ", tmpString));

	  if (_isItem == false)
	    {
	      if (explode[0] == "<title>")
		this->_rss->setTitle(explode[1]);
	      else if (explode[0] == "<description>")
		this->_rss->setDescription(explode[1]);
	      else if (explode[0] == "<link>")
		this->_rss->setLink(explode[1]);
	      else if (explode[0] == "<pubDate>")
		this->_rss->setPubDate(explode[1]);
	      else if (explode[0] == "<lastBuiltDate>")
		this->_rss->setLastBuiltDate(explode[1]);
	      else if (explode[0] == "<image>")
		this->_rss->setImage(explode[1]);
	      else if (explode[0] == "<language>")
		this->_rss->setLanguage(explode[1]);
	      else if (explode[0] == "<item>")
		{
		  if (this->_rss->_nbItem > 10)
		    {
		      delete this->_rss->_items[0];
		      this->_rss->_nbItem = 0;
		    }
		  this->_rss->_items[this->_rss->_nbItem++] = new item();
		  this->_isItem = true;
		}	
	    }

	  else
	    {
	      if (explode[0] == "<\item>")
		this->_isItem = false;
	      else if (explode[0] == "<title>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setTitle(explode[1]);
	      else if (explode[0] == "<description>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setDescription(explode[1]);
	      else if (explode[0] == "<link>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setLink(explode[1]);
	      else if (explode[0] == "<pubDate>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setPubDate(explode[1]);
	      else if (explode[0] == "<author>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setAuthor(explode[1]);
	      else if (explode[0] == "<category>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setCategory(explode[1]);
	      else if (explode[0] == "<comments>")
		this->_rss->_items[this->_rss->_nbItem - 1]->setComments(explode[1]);
	    }

	  delete buf;
	  lineLength = file.readLine(buf, sizeof(buf));
	}
    }
}
