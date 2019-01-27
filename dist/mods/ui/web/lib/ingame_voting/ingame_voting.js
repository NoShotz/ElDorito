
dew.ingameVoting = {};
dew.ingameVoting.makeWidget = function (containerElement) {
    return (function () {
        let voteAction = '';
        let votesNeeded = 0;
        let hasFocus = false;
        let isHidden = true;
        let hasVoted = false;
        let callbacks = {};

        render();

        var voted = false;
        dew.on('variable_update', function (e) {
            let voteKickWidget = document.getElementById('chatVoteWidget');

            for (let v of e.data) {
                switch (v.shortName) {
                    case 'chat_votes_needed_client':
                        votesNeeded = parseInt(v.value);
                        render();
                        break;
                    case 'chat_vote_started_client':
                        isHidden = !parseInt(v.value);
                        render();
                        emit(v.value ? 'vote_started' : 'vote_ended');
                        break;
                    case 'chat_vote_action_client':
                        voteAction = v.value;
                        render();
                        break;
                    case 'chat_vote_started_by_uid_client':
                        dew.getSessionInfo().then(result => {
                            hasVoted = result.playerInfo.Uid === v.value;
                            render();
                        });
                        break;
                }
            }
        });

        return {
            on: function (eventName, cb) {
                if (!callbacks[eventName])
                    callbacks[eventName] = [];
                callbacks[eventName].push(cb);
            },
            focus: function () {
                hasFocus = true;
            },
            blur: function () {
                hasFocus = false;
            },
            toggleVisibility: function (visible) {
                isHidden = !visible;
            },
            vote: submitVote,
            render: render
        }

        function render() {

            let visible = !isHidden && voteAction && voteAction.length > 0;

            let html = `
            <span class="">
                <span class="chat_vote_text_secondary" >${votesNeeded}</span> more votes needed to
                <span class="chat_vote_text_secondary">${escapeHtml(voteAction)}</span>
            </span>
                <button data-target="chatVoteButton" class="chat_vote_button" ${(!hasFocus || hasVoted) ? 'style="display:none"' : ''}>
                <img style="height:20px; margin-right:5px" src="dew://assets/buttons/360_Y.png"> Vote</button>
            `;


            if (!visible) {
                containerElement.style.display = 'none';
            }
            else {
                containerElement.style.display = 'flex';
            }
            containerElement.innerHTML = html;
            containerElement.querySelector('button[data-target="chatVoteButton"]').onclick = function () {
                submitVote();
            };
        }

        function emit(eventName, data) {
            let funcs = callbacks[eventName];
            if (funcs) {
                for (cb of funcs)
                    cb(data);
            }
        }

        function submitVote() {
            hasVoted = true;
            render();
            dew.sendChat('!yes', false);
        }
    })();
}

function escapeHtml(str) {
    var div = document.createElement('div');
    div.appendChild(document.createTextNode(str));
    return div.innerHTML;
}

