#ifndef FILE_H
#define FILE_H
#include<fstream>
#include "String.h"

class File {
	protected:
		String data;
		String path;
		bool opened;

		virtual bool saveData(const String&);
	public:
		File(const String& = "", bool = false);
		
		virtual ~File();
		virtual bool open(const String&);
		virtual bool save();
		virtual bool saveAs(const String&);
		virtual bool close();
		void setData(const String&);
		void setPath(const String&);

		static String getFileName(const String&, bool = true);
		String getData() const;
		String getPath() const;
		bool isOpened() const;
};
#endif