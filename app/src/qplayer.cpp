#include "qplayer.h"

#include <iostream>

QPlayer::QPlayer(QWidget *parent) {
    

    // progress_bar_song = new QSlider(box);
    // QSlider *progress_bar_sound;

    button_play = new QSuperButton(ButtonType::Play);
    button_prev = new QToolButton();
    button_next = new QToolButton();
    button_skip_fwd = new QToolButton();
    button_skip_bck = new QToolButton();

    button_prev->setIcon(QIcon(":/prev.png"));
    button_next->setIcon(QIcon(":/next.png"));
    button_skip_fwd->setIcon(QIcon(":/skip_fwd.png"));
    button_skip_bck->setIcon(QIcon(":/skip_back.png"));
    button_prev->setIconSize({30, 30});
    button_next->setIconSize({30, 30});
    button_skip_fwd->setIconSize({30, 30});
    button_skip_bck->setIconSize({30, 30});

    button_shuffle = new QSuperButton(ButtonType::Shuffle);
    button_loop = new QSuperButton(ButtonType::Loop);

    label_title = new QLabel("Title of this awesome song");
    label_artist = new QLabel("Artist Name");
    label_start_time = new QLabel("00:00");
    label_end_time = new QLabel("99:99");

    icon_quiet = new QLabel();
    icon_loud = new QLabel();
    slider_song = new QSlider(Qt::Horizontal);

    player_widget = new QWidget();
    player_widget->setObjectName("Player");
    player_widget->setMinimumSize(200, 200);
    setupLayouts();

    icon_quiet->setPixmap(QPixmap(":/quiet.png").scaled(30, 30));
    icon_loud->setPixmap(QPixmap(":/loud.png").scaled(30, 30));

    slider_sound = new QSlider(Qt::Horizontal);
    slider_sound->setMinimumSize(100, 10);
    slider_sound->setMaximumSize(100, 10);
    icon_quiet->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    button_playlist = new QSuperButton(ButtonType::Playlist);

    edit_search = new QLineEdit();
    edit_search->setPlaceholderText("Search");

    left->addWidget(button_prev);
    left->addWidget(button_skip_bck);
    left->addWidget(button_play);
    left->addWidget(button_skip_fwd);
    left->addWidget(button_next);
    left->addSpacing(100);
    left->addWidget(player_widget);

    center->addWidget(button_shuffle, 0, 0, 1, 1);
    center->addWidget(button_loop, 0, 3, 1, 1);
    center->addWidget(label_title, 0, 1, 2, 1, Qt::AlignCenter);
    center->addWidget(label_artist, 1, 1, 2, 2, Qt::AlignCenter);
    center->addWidget(label_start_time, 2, 0, 1, 1, Qt::AlignCenter);
    center->addWidget(label_end_time, 2, 3, 1, 1, Qt::AlignCenter);
    center->addWidget(slider_song, 3, 0, 5, 5);

    right->addSpacing(100);
    right->addWidget(icon_quiet);
    right->addWidget(slider_sound);
    right->addWidget(icon_loud);
    right->addSpacing(30);
    right->addWidget(edit_search);
    right->addSpacing(30);
    right->addWidget(button_playlist);

}

QPlayer::~QPlayer() {
    delete main;

    // delete left;
    // delete center;
    // delete right;
}

void QPlayer::setupLayouts() {
    main = new QHBoxLayout(this);

    left = new QHBoxLayout();
    center = new QGridLayout(player_widget);
    right = new QHBoxLayout();

    main->addLayout(left);
    // main->addLayout(center);
    main->addLayout(right);
}
