#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	// delete shaders only in destructor. There might be an ubershader.
	// shaders
	std::map<std::string, Shader*>::iterator shad_it;
	for (shad_it=_shaders.begin(); shad_it!=_shaders.end(); ++shad_it) {
		if (shad_it->second != NULL) {
			//std::cout << shad_it->first << " => " << shad_it->second << '\n';
			deleteShader(shad_it->first);
		}
	}
	_shaders.clear();
}

// Shaders
Shader* ResourceManager::getShader(const std::string& vs, const std::string& fs)
{
	std::string filename;
	filename = vs;
	std::string tmp("_");
	filename.append(tmp);
	filename.append(fs);
	if (_shaders[filename] != NULL) {
		//std::cout << "return existing resource: " << filename << " (shader)" << std::endl;
		return _shaders[filename];
	} else {
		Shader* s = new Shader();
		std::string fss = _prefix;
		fss.append(fs);
		std::string vss = _prefix;
		vss.append(vs);
		s->loadShaders(vss.c_str(), fss.c_str());
		_shaders[filename] = s;

		return s;
	}

	return NULL;
}

void ResourceManager::deleteShader(const std::string& shadername)
{
	std::string filename = _prefix;
	filename.append(shadername);

	delete _shaders[filename];
	_shaders[filename] = NULL;
}