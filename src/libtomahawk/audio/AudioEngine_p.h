
#include <phonon/MediaObject>
#include <phonon/AudioOutput>
#include <phonon/BackendCapabilities>

#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QTemporaryFile>

class AudioEnginePrivate : public QObject
{
Q_OBJECT

public:
    AudioEnginePrivate( AudioEngine* q )
        : q_ptr ( q )
    {
    }
    AudioEngine* q_ptr;
    Q_DECLARE_PUBLIC ( AudioEngine )


public slots:
    void onStateChanged( Phonon::State newState, Phonon::State oldState );

private:
    QSharedPointer<QIODevice> m_input;

    Tomahawk::query_ptr m_stopAfterTrack;
    Tomahawk::result_ptr m_currentTrack;
    Tomahawk::playlistinterface_ptr m_playlist;
    Tomahawk::playlistinterface_ptr m_currentTrackPlaylist;
    Tomahawk::playlistinterface_ptr m_queue;

    Phonon::MediaObject* m_mediaObject;
    Phonon::AudioOutput* m_audioOutput;

    unsigned int m_timeElapsed;
    bool m_expectStop;
    bool m_waitingOnNewTrack;

    mutable QStringList m_supportedMimeTypes;

    AudioState m_state;
    QQueue< AudioState > m_stateQueue;
    QTimer m_stateQueueTimer;

    uint_fast8_t m_underrunCount;
    bool m_underrunNotified;

    QTemporaryFile* m_coverTempFile;

    static AudioEngine* s_instance;
};
