#include "rss.h"

rss::rss(Qstring version): _version(version)
{
  this->_metaVersion = true;
  this->_metaTitle = false;
  this->_metaDesc = false;
  this->_metaLink = false;
  this->_nbItem = 0;
}

rss::~rss()
{
}

void	rss::setVersion(Qstring version)
{
  this->_version = version;
  this->_metaVersion = true;
}

void	rss::setTitle(Qstring title)
{
  this->_title = title;
  this->_metaTitle = true;
}

void	rss::setDescription(Qstring desc)
{
  this->_description = desc;
  this->_metaDesc = true;
}

void	rss::setLink(Qstring link)
{
  this->_link = link;
  this->_metaLink = true;
}

void	rss::setPubDate(Qstring date)
{
  this->_pubDate = date;
}

void	rss::setLastBuiltDate(Qstring date)
{
  this->_LastBuiltDate = date;
}

void	rss::setImage(Qstring img)
{
  this->_image = img;
}

void	rss::setLanguage(Qstring lg)
{
  this->_language = lg;
}

void	rss::getVersion() const
{
  return this->_version;
}

Qstring	rss::getTitle() const
{
  return this->_title;
}

Qstring	rss::getDescription() const
{
  return this->_description;
}

Qstring	rss::getLink() const
{
  return this->_link;
}

Qstring	rss::getPubDate() const
{
  return this->_pubDate;
}

Qstring	rss::getLastBuiltDate() const
{
  return this->_lastBuiltDate;
}

Qstring	rss::getImage() const
{
  return this->_image;
}

Qstring	rss::getLanguage() const
{
  return this->_language;
}

bool	rss::verifValid() const
{
  if (this->_metaTitle == true && this->_metaDesc == true && this->_metaLink == true && this->_metaVersion == true)
    return true;
  return false;
}
