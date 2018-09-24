// Library Includes
#include<assert.h>

// Project Includes 
#include"AssetManager.h"

// Initialise the static refrence for our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

// Constuctor 
AssetManager::AssetManager()
	:  m_textures      ()
	,  m_soundBuffers  ()
	,  m_fonts         ()

{
	// Throw an error and stop execution (in debug mode) if a copy
	// of this class has already been created
	assert(s_instance == nullptr);

	// Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created 
	s_instance = this;

}

 sf::Texture& AssetManager::GetTexture(std::string _fileName)
 {
	 // Create an iterator  to hold a key and value pair
	 // And search for the required key 
	 // using the passed in the file name 
	 auto KeyValuePair = s_instance->m_textures.find(_fileName);
	 // "auto" in this case is equivalent  to writing 
	 // std::map<std::string, sf::texture>::iterator
	 // this keyword (auto) can be used in cases where the
	 // compiler can figure out the type of a variable for you 
	 // YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS 

	 // Did we find the texture? (aka was it already loaded?)
	 //(iterator will be at the end if we did NOT find it)

	 if (KeyValuePair != s_instance->m_textures.end())
	 {
		 // YES! we found it 
		 return KeyValuePair->second;
	 }
	 else
	 {
		 // NO! we didn't find it!

		 // Lets create it then!

		 // Create a new key value pair using the filename 
		 // The subscript [] operator creates an entry in
		 // the map if there is not already one

		 sf::Texture& texture = s_instance->m_textures[_fileName];
		 // blank texture has been created 
		 // Now just load it from file using sfml
		 texture.loadFromFile(_fileName);

		 // return the texture to the calling code 
		 return texture;
	 }
 }