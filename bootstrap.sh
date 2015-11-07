sudo yum -y update
sudo yum -y groupinstall 'Development Tools'
sudo yum -y install git vim zsh

cat > /home/vagrant/.gitconfig << EOF
[user]
	name = Bryce Davis
	email = me@bryceadavis.com
[core]
	editor = vim
[alias]
	co = checkout
	st = status
	ci = commit
	br = branch
	last = log -1 HEAD
	g = log --graph --oneline --decorate
	df = diff

EOF

cat > /home/vagrant/.zshrc << EOF
# Created by newuser for 5.0.2
cd /vagrant

alias gitc="git commit -am"

EOF