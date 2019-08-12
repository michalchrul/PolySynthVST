/*
  ==============================================================================

    SynthSound.h
    Created: 9 Aug 2019 3:03:04pm
    Author:  micha

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote(int /*midinote number*/)
	{
		return true;
	}
	bool appliesToChannel(int /*midiChannel*/)
	{
		return true;
	}

};
