var widget = dew.ingameVoting.makeWidget(document.getElementById('voteWidget'));
widget.on('vote_started', dew.show);
widget.on('vote_ended', dew.hide);
