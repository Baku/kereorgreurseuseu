#include "rss.h"

rss::rss()
{
  this->_metaTitle = false;
  this->_metaDesc = false;
  this->_metaLink = false;
  this->_nbItem = 0;
}

rss::~rss()
{
}

void	rss::setTitle(std::string title)
{
  this->_title = title;
  this->_metaTitle = true;
}

void	rss::setDescription(std::string desc)
{
  this->_description = desc;
  this->_metaDesc = true;
}

void	rss::setLink(std::string link)
{
  this->_link = link;
  this->_metaLink = true;
}

void	rss::setPubDate(std::string date)
{
  this->_pubDate = date;
}

void	rss::setLastBuildDate(std::string date)
{
  this->_lastBuildDate = date;
}

void	rss::setImage(std::string img)
{
  this->_image = img;
}

void	rss::setLanguage(std::string lg)
{
  this->_language = lg;
}

std::string	rss::getTitle() const
{
  return this->_title;
}

std::string	rss::getDescription() const
{
  return this->_description;
}

std::string	rss::getLink() const
{
  return this->_link;
}

std::string	rss::getPubDate() const
{
  return this->_pubDate;
}

std::string	rss::getLastBuildDate() const
{
  return this->_lastBuildDate;
}

std::string	rss::getImage() const
{
  return this->_image;
}

std::string	rss::getLanguage() const
{
  return this->_language;
}

bool	rss::verifValid() const
{
  if (this->_metaTitle == true && this->_metaDesc == true && this->_metaLink == true)
    return true;
  return false;
}
